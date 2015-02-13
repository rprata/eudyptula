obj-m += hello.o

kernel_version ?= $(shell uname -r)

all:
	make -C /lib/modules/$(kernel_version)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(kernel_version)/build M=$(PWD) clean
