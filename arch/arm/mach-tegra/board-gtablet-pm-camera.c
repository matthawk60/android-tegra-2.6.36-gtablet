/*
 * Camera low power control via GPIO
 *
 * Copyright (C) 2011 Eduardo José Tagle <ejtagle@tutopia.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */ 

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <asm/mach-types.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/setup.h>
#include <linux/if.h>
#include <linux/skbuff.h>
#include <linux/random.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/rfkill.h>
#include <linux/mutex.h>
#include <linux/regulator/consumer.h>

#include <mach/hardware.h>
#include <asm/mach-types.h>

#include "board-gtablet.h"
#include "gpio-names.h"

struct gtablet_pm_camera_data {
	struct regulator *regulator;
#ifdef CONFIG_PM
	int pre_resume_state;
#endif
	int state;
};


/* Power control */
static void __gtablet_pm_camera_power(struct device *dev, unsigned int on)
{
	struct gtablet_pm_camera_data *camera_data = dev_get_drvdata(dev);

	/* Avoid turning it on if already on */
	if (camera_data->state == on)
		return;
	
	if (on) {
		dev_info(dev, "Enabling Camera\n");
	
		regulator_enable(camera_data->regulator);
	
		/* Camera power on sequence */
		gpio_set_value(GTABLET_CAMERA_POWER, 0); /* Powerdown */
		msleep(2);
		gpio_set_value(GTABLET_CAMERA_POWER, 1); /* Powerup */
		msleep(2);

		
	} else {
		dev_info(dev, "Disabling Camera\n");
		
		gpio_set_value(GTABLET_CAMERA_POWER, 0); /* Powerdown */
		
		regulator_disable(camera_data->regulator);

	}
	
	/* store new state */
	camera_data->state = on;
	
}

static ssize_t camera_read(struct device *dev, struct device_attribute *attr,
		       char *buf)
{
	int ret = 0;
	struct gtablet_pm_camera_data *camera_data = dev_get_drvdata(dev);
	
	if (!strcmp(attr->attr.name, "power_on")) {
		if (camera_data->state)
			ret = 1;
	}

	if (!ret) {
		return strlcpy(buf, "0\n", 3);
	} else {
		return strlcpy(buf, "1\n", 3);
	}
}

static ssize_t camera_write(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	unsigned long on = simple_strtoul(buf, NULL, 10);
	/*struct gtablet_pm_camera_data *camera_data = dev_get_drvdata(dev);*/

	if (!strcmp(attr->attr.name, "power_on")) {
		__gtablet_pm_camera_power(dev, on);
	} 

	return count;
}

static DEVICE_ATTR(power_on, 0644, camera_read, camera_write);
static DEVICE_ATTR(reset, 0644, camera_read, camera_write);

#ifdef CONFIG_PM
static int gtablet_camera_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct gtablet_pm_camera_data *camera_data = dev_get_drvdata(&pdev->dev);

	dev_dbg(&pdev->dev, "suspending\n");

	camera_data->pre_resume_state = camera_data->state;
	__gtablet_pm_camera_power(&pdev->dev, 0);

	return 0;
}

static int gtablet_camera_resume(struct platform_device *pdev)
{
	struct gtablet_pm_camera_data *camera_data = dev_get_drvdata(&pdev->dev);
	dev_dbg(&pdev->dev, "resuming\n");

	__gtablet_pm_camera_power(&pdev->dev, camera_data->pre_resume_state);
	return 0;
}
#else
#define gtablet_camera_suspend	NULL
#define gtablet_camera_resume		NULL
#endif

static struct attribute *gtablet_camera_sysfs_entries[] = {
	&dev_attr_power_on.attr,
	&dev_attr_reset.attr,
	NULL
};

static struct attribute_group gtablet_camera_attr_group = {
	.name	= NULL,
	.attrs	= gtablet_camera_sysfs_entries,
};

/* ----- Initialization/removal -------------------------------------------- */
static int __init gtablet_camera_probe(struct platform_device *pdev)
{
	struct regulator *regulator;
	struct gtablet_pm_camera_data *camera_data;

	camera_data = kzalloc(sizeof(*camera_data), GFP_KERNEL);
	if (!camera_data) {
		dev_err(&pdev->dev, "no memory for context\n");
		return -ENOMEM;
	}
	dev_set_drvdata(&pdev->dev, camera_data);

	regulator = regulator_get(&pdev->dev, "vdd_camera");
	if (IS_ERR(regulator)) {
		dev_err(&pdev->dev, "unable to get regulator 0\n");
		kfree(camera_data);
		dev_set_drvdata(&pdev->dev, NULL);
		return -ENODEV;
	}

	camera_data->regulator = regulator;

	
	/* Init io pins and disable camera */
	gpio_request(GTABLET_CAMERA_POWER, "camera_power");
	gpio_direction_output(GTABLET_CAMERA_POWER, 0);

	dev_info(&pdev->dev, "Camera power management driver registered\n");
	
	return sysfs_create_group(&pdev->dev.kobj, &gtablet_camera_attr_group);
}

static int gtablet_camera_remove(struct platform_device *pdev)
{
	struct gtablet_pm_camera_data *camera_data = dev_get_drvdata(&pdev->dev);

	sysfs_remove_group(&pdev->dev.kobj, &gtablet_camera_attr_group);

	if (!camera_data || !camera_data->regulator)
		return 0;

	__gtablet_pm_camera_power(&pdev->dev, 0);
	
	regulator_put(camera_data->regulator);	

	kfree(camera_data);
	dev_set_drvdata(&pdev->dev, NULL);
	
	return 0;
}

static struct platform_driver gtablet_camera_driver_ops = {
	.probe		= gtablet_camera_probe,
	.remove		= gtablet_camera_remove,
	.suspend	= gtablet_camera_suspend,
	.resume		= gtablet_camera_resume,
	.driver		= {
		.name		= "gtablet-pm-camera",
	},
};

static int __devinit gtablet_camera_init(void)
{
	return platform_driver_register(&gtablet_camera_driver_ops);
}

static void gtablet_camera_exit(void)
{
	platform_driver_unregister(&gtablet_camera_driver_ops);
}

module_init(gtablet_camera_init);
module_exit(gtablet_camera_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eduardo José Tagle <ejtagle@tutopia.com>");
MODULE_DESCRIPTION("Shuttle CAMERA power management");
