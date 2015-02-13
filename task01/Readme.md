# Task 01 - Hello Module

## Description

Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!" Be sure to make
the module able to be unloaded as well.

The Makefile should be able to build the kernel module against the
source of the currently-running kernel as well as being able to accept
an arbitrary kernel sources directory from an environment variable.

## Build module for current kernel

```bash
$ make
make -C /lib/modules/3.2.0-76-generic-pae/build M=/home/rcprata/Codes/eudyptula/task01 modules
make[1]: Entering directory `/usr/src/linux-headers-3.2.0-76-generic-pae'
  CC [M]  /home/rcprata/Codes/eudyptula/task01/hello.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/rcprata/Codes/eudyptula/task01/hello.mod.o
  LD [M]  /home/rcprata/Codes/eudyptula/task01/hello.ko
make[1]: Leaving directory `/usr/src/linux-headers-3.2.0-76-generic-pae'

```

## Show module info

```bash
$ modinfo hello.ko
modinfo hello.ko
filename:       hello.ko
description:    A simple Linux Kernel Module that when loaded prints to the kernel debug log level: "Hello World!"
author:         Renan Prata
license:        GPL
srcversion:     B9738DAC04E924C4A7E76E0
depends:        
vermagic:       3.2.0-76-generic-pae SMP mod_unload modversions 686
```

## Install module

```bash
$ sudo insmod ./hello.ko
$ dmesg | tail -1
[ 1325.631657] Hello world!
```

# Check module

```bash
$ lsmod |grep hello
hello                    892  0
```

## Uninstall module

```bash
$ sudo rmmod hello.ko
$ dmesg | tail -1
[ 1418.307920] Goodbye world!
```

## Cleanup

```bash
$ make clean
make -C /lib/modules/3.2.0-76-generic-pae/build M=/home/rcprata/Codes/eudyptula/task01 clean
make[1]: Entering directory `/usr/src/linux-headers-3.2.0-76-generic-pae`
  CLEAN   /home/rcprata/Codes/eudyptula/task01/.tmp_versions
  CLEAN   /home/rcprata/Codes/eudyptula/task01/Module.symvers
make[1]: Leaving directory `/usr/src/linux-headers-3.2.0-76-generic-pae`
```

## Compile to other kernel versions

You could list all kernel versions using this command (ubuntu distro). Please, confirm that the 'build' folder is within the kernel directory (/lib/module/$(kernel_version)):
```bash
$ dpkg --list | grep linux-image
[...]
ii  linux-image-3.2.0-29-generic-pae       3.2.0-29.46                                         Linux kernel image for version 3.2.0 on 32 bit x86 SMP
ii  linux-image-3.2.0-41-generic-pae       3.2.0-41.66                                         Linux kernel image for version 3.2.0 on 32 bit x86 SMP
ii  linux-image-3.2.0-43-generic-pae       3.2.0-43.68                                         Linux kernel image for version 3.2.0 on 32 bit x86 SMP
ii  linux-image-3.2.0-44-generic-pae       3.2.0-44.69                                         Linux kernel image for version 3.2.0 on 32 bit x86 SMP
[...]
```

So, you could setup 'kernel_version' environment variable to change kernel version in compilation:

```bash
$ export kernel_version=3.2.0-74-generic-pae
$ make
make -C /lib/modules/3.2.0-74-generic-pae/build M=/home/rcprata/Codes/eudyptula/task01 modules
make[1]: Entering directory `/usr/src/linux-headers-3.2.0-74-generic-pae`
  CC [M]  /home/rcprata/Codes/eudyptula/task01/hello.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/rcprata/Codes/eudyptula/task01/hello.mod.o
  LD [M]  /home/rcprata/Codes/eudyptula/task01/hello.ko
make[1]: Leaving directory `/usr/src/linux-headers-3.2.0-74-generic-pae`
[...]
$ unset kernel_version
```