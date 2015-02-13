obj-m += hello.o

LINUX_KERNEL_VERSION ?= $(shell uname -r)

all:
	make -C /lib/modules/$(LINUX_KERNEL_VERSION)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(LINUX_KERNEL_VERSION)/build M=$(PWD) clean
