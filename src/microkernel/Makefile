CC = x86_64-elf-gcc
LD = x86_64-elf-ld
CFLAGS = -ffreestanding -O2 -Wall -Wextra -Iinclude
LDFLAGS = -T linker.ld -nostdlib

SRCS = entry.c scheduler.c ipc.c memory.c drivers/console.c
OBJS = $(SRCS:.c=.o)

all: enochcore.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

drivers/console.o: drivers/console.c
	$(CC) $(CFLAGS) -c $< -o $@

enochcore.bin: $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -f *.o drivers/*.o enochcore.bin

run: enochcore.bin
	qemu-system-x86_64 -kernel enochcore.bin 