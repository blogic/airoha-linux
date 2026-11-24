// SPDX-License-Identifier: GPL-2.0-only
/*
 * Airoha GPIO system controller
 *
 * Copyright (C) 2026 John Crispin <john@phrozen.org>
 */

#include <linux/array_size.h>
#include <linux/mfd/core.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/platform_device.h>

static const struct mfd_cell an7589_gpio_sysctl_cells[] = {
	MFD_CELL_NAME("airoha-an7589-pwm"),
};

static int airoha_gpio_sysctl_probe(struct platform_device *pdev)
{
	return devm_mfd_add_devices(&pdev->dev, PLATFORM_DEVID_NONE,
				    an7589_gpio_sysctl_cells,
				    ARRAY_SIZE(an7589_gpio_sysctl_cells),
				    NULL, 0, NULL);
}

static const struct of_device_id airoha_gpio_sysctl_of_match[] = {
	{ .compatible = "airoha,an7589-gpio-sysctl" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, airoha_gpio_sysctl_of_match);

static struct platform_driver airoha_gpio_sysctl_driver = {
	.probe = airoha_gpio_sysctl_probe,
	.driver = {
		.name = "airoha-gpio-sysctl",
		.of_match_table = airoha_gpio_sysctl_of_match,
	},
};
module_platform_driver(airoha_gpio_sysctl_driver);

MODULE_AUTHOR("John Crispin <john@phrozen.org>");
MODULE_DESCRIPTION("Airoha GPIO system controller driver");
MODULE_LICENSE("GPL");
