/*
 * arch/arm/mach-tegra/board-gtablet-aes.c
 *
 * Copyright (C) 2011 Eduardo Jos� Tagle <ejtagle@tutopia.com>
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

#include <linux/console.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/reboot.h>
#include <linux/memblock.h>

#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/time.h>
#include <asm/setup.h>

#include <mach/io.h>
#include <mach/iomap.h>
#include <mach/irqs.h>
#include <mach/nand.h>
#include <mach/iomap.h>

#include "board.h"
#include "board-gtablet.h"
#include "clock.h"
#include "gpio-names.h"
#include "devices.h"

static struct platform_device *gtablet_aes_devices[] __initdata = {
	&tegra_aes_device,
};

int __init gtablet_aes_register_devices(void)
{
	return platform_add_devices(gtablet_aes_devices, ARRAY_SIZE(gtablet_aes_devices));
}