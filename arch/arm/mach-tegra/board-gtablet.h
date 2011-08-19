/*
 * arch/arm/mach-tegra/board-gtablet.h
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

#ifndef _MACH_TEGRA_BOARD_GTABLET_H
#define _MACH_TEGRA_BOARD_GTABLET_H

#define TPS6586X_INT_BASE	TEGRA_NR_IRQS

#define GTABLET_BT_RESET 		TEGRA_GPIO_PU0 	/* 0= reset asserted */

#define GTABLET_KEY_VOLUMEUP 	TEGRA_GPIO_PD4 	/* 0=pressed */
#define GTABLET_KEY_VOLUMEDOWN 	TEGRA_GPIO_PV4 	/* 0=pressed */
#define GTABLET_KEY_POWER 		TEGRA_GPIO_PV2 	/* 0=pressed */
#define GTABLET_KEY_BACK		TEGRA_GPIO_PH0	/* 0=pressed */

/* #define GTABLET_EMC_SAMSUNG		*/
/* #define GTABLET_EMC_ELPIDA50NM	*/
/* #define GTABLET_EMC_ELPIDA40NM	*/

#define GTABLET_CAMERA_POWER 	TEGRA_GPIO_PBB5 /* 1=powered on */
#define GTABLET_CAMERA_ROTATION	TEGRA_GPIO_PX7

#define GTABLET_NAND_WPN		TEGRA_GPIO_PC7	/* NAND flash write protect: 0=writeprotected */

#define GTABLET_BL_ENB			TEGRA_GPIO_PD3
#define GTABLET_LVDS_SHUTDOWN	TEGRA_GPIO_PB2 // Is this right?
#define GTABLET_EN_VDD_PANEL	TEGRA_GPIO_PC6 
#define GTABLET_BL_VDD			TEGRA_GPIO_PW0
#define GTABLET_BL_PWM			TEGRA_GPIO_PU3 /* PWM */
#define GTABLET_HDMI_ENB		TEGRA_GPIO_PV5 /* unconfirmed */ // Does gtablet have HDMI enbl?
#define GTABLET_HDMI_HPD		TEGRA_GPIO_PN7 /* 1=HDMI plug detected */

#define GTABLET_BL_PWM_ID		0				/* PWM0 controls backlight */

#define GTABLET_FB_PAGES		2				/* At least, 2 video pages */
#define GTABLET_FB_HDMI_PAGES	2				/* At least, 2 video pages for HDMI */

// Gtablet memory is 2xSZ_512M
#define GTABLET_MEM_SIZE 		SZ_512M			/* Total memory */
#define GTABLET_MEM_BANKS		2

#define GTABLET_GPU_MEM_SIZE 		SZ_128M		/* Memory reserved for GPU */
//#define GTABLET_GPU_MEM_SIZE 	SZ_64M			/* Memory reserved for GPU */

#define GTABLET_FB1_MEM_SIZE 	SZ_8M			/* Memory reserved for Framebuffer 1: LCD */
#define GTABLET_FB2_MEM_SIZE 	SZ_8M			/* Memory reserved for Framebuffer 2: HDMI out */

#define DYNAMIC_GPU_MEM 1						/* use dynamic memory for GPU */

// TPS6586x GPIOs as registered 
#define PMU_GPIO_BASE		(TEGRA_NR_GPIOS) 
#define PMU_GPIO0 			(PMU_GPIO_BASE)
#define PMU_GPIO1 			(PMU_GPIO_BASE + 1) 
#define PMU_GPIO2 			(PMU_GPIO_BASE + 2)
#define PMU_GPIO3 			(PMU_GPIO_BASE + 3)

#define PMU_IRQ_BASE		(TEGRA_NR_IRQS)
#define PMU_IRQ_RTC_ALM1 	(PMU_IRQ_BASE + TPS6586X_INT_RTC_ALM1)

#define	GTABLET_ENABLE_VDD_VID	TEGRA_GPIO_PD1	/* 1=enabled.  Powers HDMI. Wait 500uS to let it stabilize before returning */

// TODO: Find whether there are any definitions for these?
/*#define GTABLET_SDIO0_CD		TEGRA_GPIO_PI5
#define GTABLET_SDIO0_POWER	TEGRA_GPIO_PD0*/	/* SDIO0 and SDIO2 power */

#define GTABLET_SDHC_CD		TEGRA_GPIO_PI5
#define GTABLET_SDHC_WP		-1	/*1=Write Protected */
#define GTABLET_SDHC_POWER	TEGRA_GPIO_PD0

#define GTABLET_TS_IRQ		TEGRA_GPIO_PJ7
#define GTABLET_TS_RESET	TEGRA_GPIO_PH1
#define GTABLET_TS_POWER	TEGRA_GPIO_PK2
//#define GTABLET_TS_DISABLE	TEGRA_GPIO_PAA6 /* 0=enabled */

//#define GTABLET_FB_NONROTATE TEGRA_GPIO_PH1 /*1 = screen rotation locked */

#define GTABLET_WLAN_POWER 	TEGRA_GPIO_PK5
#define GTABLET_WLAN_RESET 	TEGRA_GPIO_PK6

#define GTABLET_BT_RST		TEGRA_GPIO_PU0

#define GTABLET_LOW_BATT	TEGRA_GPIO_PW3 /*(0=low battery)*/
#define GTABLET_IN_S3		TEGRA_GPIO_PAA7 /*1 = in S3 */

//#define GTABLET_USB0_VBUS	TEGRA_GPIO_PB0		/* 1= VBUS usb0 */
#define GTABLET_USB1_RESET		TEGRA_GPIO_PV1	/* 0= reset */

#define GTABLET_HP_DETECT	TEGRA_GPIO_PW2 	/* HeadPhone detect for audio codec: 1=Hedphone plugged */

#define GTABLET_NVEC_REQ	TEGRA_GPIO_PD0	/* Set to 0 to send a command to the NVidia Embedded controller */
#define GTABLET_NVEC_I2C_ADDR 0x8a 			/* I2C address of Tegra, when acting as I2C slave */

#define GTABLET_WAKE_KEY_POWER  TEGRA_WAKE_GPIO_PV2
#define GTABLET_WAKE_KEY_RESUME TEGRA_WAKE_GPIO_PV2

/* The switch used to indicate rotation lock */
//#define SW_ROTATION_LOCK 	(SW_MAX-1)

extern void gtablet_wifi_set_cd(int val);

extern void gtablet_init_emc(void);
extern void gtablet_pinmux_init(void);
extern void gtablet_clks_init(void);

extern int gtablet_usb_register_devices(void);
extern int gtablet_audio_register_devices(void);
extern int gtablet_gpu_register_devices(void);
extern int gtablet_uart_register_devices(void);
extern int gtablet_spi_register_devices(void);
extern int gtablet_aes_register_devices(void);
extern int gtablet_wdt_register_devices(void);
extern int gtablet_i2c_register_devices(void);
extern int gtablet_power_register_devices(void);
extern int gtablet_keyboard_register_devices(void);
extern int gtablet_touch_register_devices(void);
extern int gtablet_sdhci_register_devices(void);
extern int gtablet_sensors_register_devices(void);
extern int gtablet_wlan_pm_register_devices(void);
extern int gtablet_bt_pm_register_devices(void);
extern int gtablet_nand_register_devices(void);
extern int gtablet_camera_register_devices(void);

#endif

