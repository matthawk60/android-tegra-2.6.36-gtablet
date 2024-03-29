obj-y                                   += common.o
obj-y                                   += apbio.o
obj-y                                   += io.o
obj-y                                   += irq.o legacy_irq.o
obj-y                                   += syncpt.o
obj-y                                   += clock.o
obj-y                                   += dvfs.o
obj-y                                   += timer.o
obj-y                                   += gpio.o
obj-y                                   += pinmux.o
obj-y                                   += devices.o
obj-y                                   += delay.o
obj-y                                   += powergate.o
obj-y                                   += suspend.o
obj-y                                   += fuse.o
obj-y                                   += kfuse.o
ifeq ($(CONFIG_SND_TEGRA_SOC),y)
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += tegra2_i2s.o
else
obj-y                                   += tegra_i2s_audio.o
obj-y                                   += tegra_spdif_audio.o
endif
obj-y                                   += spdif.o
obj-y                                   += tegra_das.o
obj-y                                   += mc.o
obj-$(CONFIG_USB_SUPPORT)               += usb_phy.o
obj-$(CONFIG_FIQ)                       += fiq.o
obj-$(CONFIG_TEGRA_FIQ_DEBUGGER)        += tegra_fiq_debugger.o
obj-$(CONFIG_TEGRA_PWM)                 += pwm.o
obj-$(CONFIG_TEGRA_ARB_SEMAPHORE)	+= arb_sema.o

obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += clock.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += tegra2_clocks.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += tegra2_dvfs.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += tegra2_fuse.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += tegra2_speedo.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += suspend-t2.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)		+= tegra2_save.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)		+= tegra2_emc.o
obj-$(CONFIG_CPU_V7)			+= cortex-a9.o

obj-$(CONFIG_ARCH_TEGRA_2x_SOC)		+= pinmux-t2-tables.o
obj-$(CONFIG_SMP)                       += localtimer.o
obj-$(CONFIG_SMP)                       += platsmp.o
obj-y                                   += headsmp.o
obj-$(CONFIG_ARCH_TEGRA_2x_SOC)         += headsmp-t2.o
obj-$(CONFIG_TEGRA_SYSTEM_DMA)          += dma.o
obj-$(CONFIG_CPU_FREQ)                  += cpu-tegra.o
obj-$(CONFIG_CPU_IDLE)                  += cpuidle.o
obj-$(CONFIG_TEGRA_IOVMM)               += iovmm.o
obj-$(CONFIG_TEGRA_IOVMM_GART)          += iovmm-gart.o
obj-$(CONFIG_TEGRA_MC_PROFILE)          += tegra2_mc.o

obj-${CONFIG_TEGRA_SPI_SLAVE}		+= spi_tegra_slave.o

obj-${CONFIG_MACH_HARMONY}              += board-harmony.o
obj-${CONFIG_MACH_HARMONY}              += board-harmony-pinmux.o
obj-${CONFIG_MACH_HARMONY}              += board-harmony-panel.o
obj-${CONFIG_MACH_HARMONY}              += board-harmony-sdhci.o

# Shuttle arch drivers
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-aes.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-audio.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-bootinfo.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-bt.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-camera.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-clocks.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-gps.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-gpu.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-gsm.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-i2c.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-keyboard.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-memory.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-nand.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-pinmux.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-power.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-sdhci.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-sensors.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-spi.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-touch.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-uart.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-usb.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-wdt.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle-wlan.o
obj-${CONFIG_MACH_SHUTTLE}              += board-shuttle.o
# Shuttle power management drivers
obj-${CONFIG_MACH_SHUTTLE}              += shuttle-pm-bluetooth.o
obj-${CONFIG_MACH_SHUTTLE}              += shuttle-pm-camera.o
obj-${CONFIG_MACH_SHUTTLE}              += shuttle-pm-gps.o
obj-${CONFIG_MACH_SHUTTLE}              += shuttle-pm-gsm.o
obj-${CONFIG_MACH_SHUTTLE}              += shuttle-pm-wlan.o

# Adam arch drivers
obj-${CONFIG_MACH_ADAM}              += board-adam-aes.o
obj-${CONFIG_MACH_ADAM}              += board-adam-audio.o
obj-${CONFIG_MACH_ADAM}              += board-adam-bootinfo.o
obj-${CONFIG_MACH_ADAM}              += board-adam-bt.o
obj-${CONFIG_MACH_ADAM}              += board-adam-camera.o
obj-${CONFIG_MACH_ADAM}              += board-adam-clocks.o
obj-${CONFIG_MACH_ADAM}              += board-adam-gps.o
obj-${CONFIG_MACH_ADAM}              += board-adam-gpu.o
obj-${CONFIG_MACH_ADAM}              += board-adam-gsm.o
obj-${CONFIG_MACH_ADAM}              += board-adam-i2c.o
obj-${CONFIG_MACH_ADAM}              += board-adam-keyboard.o
obj-${CONFIG_MACH_ADAM}              += board-adam-memory.o
obj-${CONFIG_MACH_ADAM}              += board-adam-nand.o
obj-${CONFIG_MACH_ADAM}              += board-adam-pinmux.o
obj-${CONFIG_MACH_ADAM}              += board-adam-power.o
obj-${CONFIG_MACH_ADAM}              += board-adam-sdhci.o
obj-${CONFIG_MACH_ADAM}              += board-adam-sensors.o
obj-${CONFIG_MACH_ADAM}              += board-adam-spi.o
obj-${CONFIG_MACH_ADAM}              += board-adam-touch.o
obj-${CONFIG_MACH_ADAM}              += board-adam-uart.o
obj-${CONFIG_MACH_ADAM}              += board-adam-usb.o
obj-${CONFIG_MACH_ADAM}              += board-adam-wdt.o
#obj-${CONFIG_MACH_ADAM}              += board-adam-wlan.o
obj-${CONFIG_MACH_ADAM}              += board-adam.o
# adam power management drivers
obj-${CONFIG_MACH_ADAM}              += board-adam-pm-bluetooth.o
obj-${CONFIG_MACH_ADAM}              += board-adam-pm-camera.o
obj-${CONFIG_MACH_ADAM}              += board-adam-pm-gps.o
obj-${CONFIG_MACH_ADAM}              += board-adam-pm-gsm.o
#obj-${CONFIG_MACH_ADAM}              += board-adam-pm-wlan.o

# Gtablet arch drivers
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-aes.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-audio.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-bootinfo.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-bt.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-camera.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-clocks.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-gpu.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-i2c.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-keyboard.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-memory.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-nand.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-pinmux.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-power.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-sdhci.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-sensors.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-spi.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-touch.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-uart.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-usb.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-wdt.o
#obj-${CONFIG_MACH_GTABLET}              += board-gtablet-wlan.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet.o
# Gtablet power management drivers
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-pm-bluetooth.o
obj-${CONFIG_MACH_GTABLET}              += board-gtablet-pm-camera.o
#obj-${CONFIG_MACH_GTABLET}              += board-gtablet-pm-wlan.o

obj-${CONFIG_MACH_VENTANA}              += board-ventana.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-pinmux.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-sdhci.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-power.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-panel.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-jack.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-sensors.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-kbc.o
obj-${CONFIG_MACH_VENTANA}              += board-ventana-memory.o

obj-${CONFIG_MACH_WHISTLER}             += board-whistler.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-pinmux.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-sdhci.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-power.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-panel.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-sensors.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-kbc.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-baseband.o
obj-${CONFIG_MACH_WHISTLER}             += board-whistler-memory.o

obj-${CONFIG_MACH_BETELGEUSE}           += board-betelgeuse.o
obj-${CONFIG_MACH_BETELGEUSE}           += board-betelgeuse-pinmux.o
obj-${CONFIG_MACH_BETELGEUSE}           += board-betelgeuse-panel.o
obj-${CONFIG_MACH_BETELGEUSE}		+= board-betelgeuse-power.o
obj-${CONFIG_MACH_BETELGEUSE}           += board-betelgeuse-sdhci.o

obj-${CONFIG_MACH_VEGA}           += board-vega.o
obj-${CONFIG_MACH_VEGA}           += board-vega-pinmux.o
obj-${CONFIG_MACH_VEGA}           += board-vega-panel.o
obj-${CONFIG_MACH_VEGA}			 += board-vega-power.o
obj-${CONFIG_MACH_VEGA}           += board-vega-sdhci.o
