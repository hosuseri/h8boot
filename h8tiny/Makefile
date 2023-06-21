SCRIPT=h8boot
CC=h8300-hms-gcc
OBJCOPY=h8300-hms-objcopy
CFLAGS=-Wall -mh -Os -c
LDFLAGS=-Wl,-Map,boot3694.map -mh -T h8300h.x -nostartfiles -nostdlib

all: h8boot

h8boot: boot3694.mot
	echo '#!/bin/sh' >$(SCRIPT)
	echo '' >>$(SCRIPT)
	echo 'LINE=/dev/ttyUSB0' >>$(SCRIPT)
	echo '' >>$(SCRIPT)
	echo 'h8boot1 -l $${LINE} <<EOF' >>$(SCRIPT)
	cat boot3694.mot >>$(SCRIPT)
	echo 'EOF' >>$(SCRIPT)
	echo '' >>$(SCRIPT)
	echo 'h8boot2 -l $${LINE} $$*' >>$(SCRIPT)
	chmod +x h8boot

boot3694.mot: boot3694.coff
	$(OBJCOPY) -O srec boot3694.coff boot3694.mot

boot3694.coff: crt0.o main.o
	$(CC) $(LDFLAGS) -o boot3694.coff crt0.o main.o

crt0.o: crt0.S
	$(CC) $(CFLAGS) crt0.S

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -f $(SCRIPT)
	rm -f boot3694.mot boot3694.coff crt0.o main.o boot3694.map
	rm -f crt0.o main.o
