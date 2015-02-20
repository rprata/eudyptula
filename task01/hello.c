/* Copyright (c) 2015 Renan Prata <renanprata@ieee.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define KERNEL_MODULE_AUTHOR "Renan Prata <renanprata@ieee.org>"
#define KERNEL_MODULE_DESC "A simple Linux Kernel Module that when loaded prints to the kernel debug log level: \"Hello World!\""

static int __init hello_init(void)
{
	printk(KERN_DEBUG "Hello World!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_DEBUG "Exiting from my Hello World!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(KERNEL_MODULE_AUTHOR);
MODULE_DESCRIPTION(KERNEL_MODULE_DESC);
