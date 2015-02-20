/* Copyright (c) 2015 Renan Prata <renanprata@ieee.com>
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

#define KERNEL_MODULE_AUTHOR "Renan Prata"
#define KERNEL_MODULE_DESC "A simple Linux Kernel Module that when loaded prints to the kernel debug log level: \"Hello World!\""

int init_module(void)
{
	printk(KERN_DEBUG "Hello World!\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_DEBUG "Cleaning my Hello World!\n");
}

MODULE_LICENSE("GPL");

MODULE_AUTHOR(KERNEL_MODULE_AUTHOR);
MODULE_DESCRIPTION(KERNEL_MODULE_DESC);
