/*
 * arch/arm/mach-tegra/board-gtablet-pinmux.c
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

#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/version.h>
#include <linux/init.h>
#include <mach/pinmux.h>

#include "gpio-names.h"

#include "board-gtablet.h"

static __initdata struct tegra_pingroup_config gtablet_pinmux[] = {
	{TEGRA_PINGROUP_ATA, TEGRA_MUX_IDE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_ATB, TEGRA_MUX_SDIO4, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_ATC, TEGRA_MUX_NAND, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_ATD, TEGRA_MUX_GMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_ATE, TEGRA_MUX_GMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_CDEV1, TEGRA_MUX_PLLA_OUT, TEGRA_PUPD_PULL_DOWN, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_CDEV2, TEGRA_MUX_OSC, TEGRA_PUPD_PULL_DOWN, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_CRTP, TEGRA_MUX_CRT, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_CSUS, TEGRA_MUX_VI_SENSOR_CLK, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DAP1, TEGRA_MUX_DAP1, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DAP2, TEGRA_MUX_GMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DAP3, TEGRA_MUX_DAP3, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DAP4, TEGRA_MUX_DAP4, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DDC, TEGRA_MUX_I2C2, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_DTA, TEGRA_MUX_VI, TEGRA_PUPD_PULL_UP, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DTB, TEGRA_MUX_VI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DTC, TEGRA_MUX_VI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DTD, TEGRA_MUX_VI, TEGRA_PUPD_PULL_UP, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DTE, TEGRA_MUX_VI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_DTF, TEGRA_MUX_I2C3, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_GMA, TEGRA_MUX_SDIO4, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GMB, TEGRA_MUX_GMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GMC, TEGRA_MUX_GMI, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GMD, TEGRA_MUX_GMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GME, TEGRA_MUX_SDIO4, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GPU, TEGRA_MUX_PWM, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GPU7, TEGRA_MUX_RTCK, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_GPV, TEGRA_MUX_PCIE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_HDINT, TEGRA_MUX_HDMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_I2CP, TEGRA_MUX_I2C, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_IRRX, TEGRA_MUX_UARTA, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_IRTX, TEGRA_MUX_UARTA, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_KBCA, TEGRA_MUX_KBC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_KBCB, TEGRA_MUX_KBC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_KBCC, TEGRA_MUX_KBC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_KBCD, TEGRA_MUX_KBC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_KBCE, TEGRA_MUX_KBC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_KBCF, TEGRA_MUX_KBC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LCSN, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LD0, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD1, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD10, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD11, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD12, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD13, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD14, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD15, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD16, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD17, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD2, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD3, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD4, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD5, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD6, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD7, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD8, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LD9, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LDC, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LDI, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LHP0, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LHP1, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LHP2, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LHS, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LM0, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LM1, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LPP, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LPW0, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LPW1, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LPW2, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LSC0, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LSC1, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LSCK, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LSDA, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LSDI, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LSPI, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LVP0, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_LVP1, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_LVS, TEGRA_MUX_DISPLAYA, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_OWC, TEGRA_MUX_OWR, TEGRA_PUPD_PULL_UP, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_PMC, TEGRA_MUX_PWR_ON, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_PTA, TEGRA_MUX_HDMI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_RM, TEGRA_MUX_I2C, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SDB, TEGRA_MUX_SDIO3, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SDC, TEGRA_MUX_SDIO3, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SDD, TEGRA_MUX_SDIO3, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SDIO1, TEGRA_MUX_SDIO1, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SLXA, TEGRA_MUX_PCIE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SLXC, TEGRA_MUX_SPI4, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SLXD, TEGRA_MUX_SPI4, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SLXK, TEGRA_MUX_PCIE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPDI, TEGRA_MUX_RSVD2, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPDO, TEGRA_MUX_RSVD2, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPIA, TEGRA_MUX_GMI, TEGRA_PUPD_PULL_DOWN, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPIB, TEGRA_MUX_GMI, TEGRA_PUPD_PULL_DOWN, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_SPIC, TEGRA_MUX_GMI, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPID, TEGRA_MUX_SPI1, TEGRA_PUPD_PULL_DOWN, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPIE, TEGRA_MUX_SPI1, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPIF, TEGRA_MUX_SPI1, TEGRA_PUPD_PULL_DOWN, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPIG, TEGRA_MUX_SPI2_ALT, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_SPIH, TEGRA_MUX_SPI2_ALT, TEGRA_PUPD_PULL_UP, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_UAA, TEGRA_MUX_ULPI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_UAB, TEGRA_MUX_ULPI, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_UAC, TEGRA_MUX_RSVD4, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_UAD, TEGRA_MUX_SPDIF, TEGRA_PUPD_NORMAL, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_UCA, TEGRA_MUX_UARTC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_UCB, TEGRA_MUX_UARTC, TEGRA_PUPD_PULL_UP, TEGRA_TRI_TRISTATE},
	{TEGRA_PINGROUP_UDA, TEGRA_MUX_UARTD, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_CK32, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_DDRC, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_PMCA, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_PMCB, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_PMCC, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_PMCD, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_PMCE, TEGRA_MUX_NONE, TEGRA_PUPD_PULL_UP, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_XM2C, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
	{TEGRA_PINGROUP_XM2D, TEGRA_MUX_NONE, TEGRA_PUPD_NORMAL, TEGRA_TRI_NORMAL},
};
	
static __initdata struct tegra_drive_pingroup_config gtablet_drive_pinmux[] = {
	/*{TEGRA_DRIVE_PINGROUP_AO1,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_2, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_AO2,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_AT1,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_AT2,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},*/
/*	{TEGRA_DRIVE_PINGROUP_CDEV1,   TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_CDEV2,   TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_CSUS,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_DAP1,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_0,  TEGRA_PULL_0,  TEGRA_SLEW_FASTEST, TEGRA_SLEW_FASTEST},
	{TEGRA_DRIVE_PINGROUP_DAP2,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_8, TEGRA_PULL_0,  TEGRA_PULL_0,  TEGRA_SLEW_FASTEST, TEGRA_SLEW_FASTEST},
	{TEGRA_DRIVE_PINGROUP_DAP3,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_8, TEGRA_PULL_0,  TEGRA_PULL_0,  TEGRA_SLEW_FASTEST, TEGRA_SLEW_FASTEST},
	{TEGRA_DRIVE_PINGROUP_DAP4,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
/*	{TEGRA_DRIVE_PINGROUP_DBG,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_2, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_DDC,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_LCD1,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_LCD2,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},*/
/*	{TEGRA_DRIVE_PINGROUP_SDMMC2,  TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_SDMMC3,  TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	/*{TEGRA_DRIVE_PINGROUP_SPI,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_UAA,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_UAB,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_UART2,   TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_UART3,   TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_1, TEGRA_PULL_18, TEGRA_PULL_22, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_VI1,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_VI2,     TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_SLOWEST},
	{TEGRA_DRIVE_PINGROUP_XM2A,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_8, TEGRA_PULL_28, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_FAST},
	{TEGRA_DRIVE_PINGROUP_XM2C,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_FAST},
	{TEGRA_DRIVE_PINGROUP_XM2D,    TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_1, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_FAST},
	{TEGRA_DRIVE_PINGROUP_XM2CLK,  TEGRA_HSM_DISABLE, TEGRA_SCHMITT_DISABLE, TEGRA_DRIVE_DIV_8, TEGRA_PULL_28, TEGRA_PULL_31, TEGRA_SLEW_SLOWEST, TEGRA_SLEW_FAST},
	{TEGRA_DRIVE_PINGROUP_MEMCOMP, TEGRA_HSM_DISABLE, TEGRA_SCHMITT_ENABLE,  TEGRA_DRIVE_DIV_8, TEGRA_PULL_31, TEGRA_PULL_31, TEGRA_SLEW_FASTEST, TEGRA_SLEW_FASTEST}, */
};

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,38)
struct tegra_gpio_table {
	int gpio;
	bool enable;
};

static void tegra_gpio_config(struct tegra_gpio_table* tab, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (tab[i].enable) {
			tegra_gpio_enable(tab[i].gpio);
		} else {
			tegra_gpio_disable(tab[i].gpio);
		}
	}
}
#endif

static struct tegra_gpio_table gpio_table[] = {
	{ .gpio = GTABLET_BT_RESET,			.enable = true },
	{ .gpio = GTABLET_KEY_VOLUMEUP,		.enable = true },
	{ .gpio = GTABLET_KEY_VOLUMEDOWN,	.enable = true },
	{ .gpio = GTABLET_KEY_POWER,		.enable = true },
	{ .gpio = GTABLET_KEY_BACK,			.enable = true },
//	{ .gpio = GTABLET_CAMERA_POWER,		.enable = true },
	{ .gpio = GTABLET_NAND_WPN,			.enable = true },
	{ .gpio = GTABLET_BL_ENB,			.enable = true },
	{ .gpio = GTABLET_LVDS_SHUTDOWN,	.enable = true },
	{ .gpio = GTABLET_EN_VDD_PANEL,		.enable = true },
	{ .gpio = GTABLET_BL_VDD,			.enable = true },
	{ .gpio = GTABLET_BL_PWM,			.enable = false }, /* We want the PWM function here! */
	{ .gpio = GTABLET_HDMI_ENB,			.enable = true },
	{ .gpio = GTABLET_HDMI_HPD,			.enable = true },
	{ .gpio = GTABLET_ENABLE_VDD_VID,	.enable = true },
	{ .gpio = GTABLET_SDHC_CD,			.enable = true },
	{ .gpio = GTABLET_SDHC_POWER,		.enable = true },
	{ .gpio = GTABLET_TS_IRQ,			.enable = true },
	{ .gpio = GTABLET_TS_POWER,		.enable = true },
	{ .gpio = GTABLET_TS_RESET,		.enable = true },
	{ .gpio = GTABLET_WLAN_POWER,		.enable = true },
	{ .gpio = GTABLET_WLAN_RESET,		.enable = true },
	{ .gpio = GTABLET_LOW_BATT,		.enable = true },
	{ .gpio = GTABLET_IN_S3,			.enable = true },
/*	{ .gpio = GTABLET_USB1_RESET,		.enable = true },*/
	{ .gpio = GTABLET_HP_DETECT,		.enable = true },
};

void __init gtablet_pinmux_init(void)
{
	tegra_pinmux_config_table(gtablet_pinmux, ARRAY_SIZE(gtablet_pinmux));
	/*tegra_drive_pinmux_config_table(gtablet_drive_pinmux,
		ARRAY_SIZE(gtablet_drive_pinmux));*/
	tegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));
}
