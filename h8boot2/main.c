#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srec.h"
#include "flash.h"
#include "serial.h"

#define DEFDEV "/dev/tty00"

char dev[32], ibuf[256];
unsigned char obuf[256];

int main(int argc, char *argv[])
{
    int i, j, k, n, ser;
    unsigned char *p, *q;
    unsigned long addr;
    struct block *b;
    FILE *fin, *fp;

    fin = stdin;
    fname = "*stdin*";
    line = 1;
    strcpy(dev, DEFDEV);

    while ((k = getopt(argc, argv, "l:")) != -1)
	switch (k) {
	case 'l':
	    strncpy(dev, optarg, sizeof(dev)-1);
	    break;
	default:
	    fprintf(stderr, "usage: boot1 [-l <device>]\n");
	    exit(2);
	}
    argc -= optind;
    argv += optind;
    if (argc > 0)
	if ((fp = fopen(argv[0], "r")) != NULL) {
	    fin = fp;
	    fname = argv[0];
	}

    for (;; line++) {
	if (srec_read_line(ibuf, sizeof ibuf, fin) == NULL)
	    break;
	if ((n = srec_parse(ibuf, obuf, sizeof obuf)) < 0)
	    break;
	if (n == 0)
	    continue;

	addr = obuf[3];
	addr = addr << 8;
	addr |= obuf[2];
	addr = addr << 8;
	addr |= obuf[1];
	addr = addr << 8;
	addr |= obuf[0];
	//fprintf(stderr, "addr = 0x%08lX\n", addr);
	q = obuf + sizeof(unsigned long);
	k = addr & 0x7F;
	for (i=n; i > 0; addr += 128) {
	    b = obtain(addr);
	    for (p=b->core+k, j=k; i > 0 && j < 128; j++, i--)
		*p++ = *q++;
	    k = 0;
	}
    }
    if (fin != stdin)
	fclose(fin);

    ser = seropen(dev);
    boot(ser);
    close(ser);

    freeall();

    return 0;
}
