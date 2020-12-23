obj-m := pen_kernelbois_register.o
CC=gcc
OBJ=test.c

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)

all: modules test.o

modules:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

test.o: $(OBJ)
	$(CC) -o $@ $<

.PHONY: clean
clean:
	rm -rf *.0 *.ko *.mod *.symvers *.order *~
