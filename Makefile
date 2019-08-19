KERNELRELEASE	?= `uname -r`
KERNEL_DIR	?= /lib/modules/$(KERNELRELEASE)/build
PWD		:= $(shell pwd)
obj-m		:= hello-world.o

all:
	@echo "Building hello-world kernel module..."
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
