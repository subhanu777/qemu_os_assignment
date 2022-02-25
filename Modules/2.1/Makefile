obj-m += loading.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

load:
	sudo dmesg -C
	sudo insmod loading.ko
	dmesg

unload:
	sudo dmesg -C
	sudo rmmod loading.ko
	dmesg


