#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "srec.h"
#include "crc.h"
#include "serial.h"

#define DEFDEV "/dev/tty00"
#define TOPCORE 0xf780
#define MAXCORE 2048

int boot(int ser, unsigned char *core, int n, int off);

char dev[32], ibuf[256];
unsigned char obuf[256];
unsigned char core[MAXCORE];

int main(int argc, char *argv[])
{
    int k, m, n, ser;
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

    for (m = 0;;) {
	if (srec_read_line(ibuf, sizeof ibuf, fin) == NULL)
	    break;
	line++;
	if ((n = srec_parse(ibuf, obuf, sizeof obuf)) < 0)
	    break;
	if (n == 0)
	    continue;
	k = obuf[3];
	k = k << 8;
	k |= obuf[2];
	k = k << 8;
	k |= obuf[1];
	k = k << 8;
	k |= obuf[0];
	k -= TOPCORE;
	if (k + n > sizeof core) {
	    fprintf(stderr, "too large.\n");
	    return 2;
	}
	memcpy(core + k, obuf + sizeof(unsigned long *), n);
	if ((k += n) > m)
	    m = k;
    }
    if (fin != stdin)
	fclose(fin);

    if ((ser = seropen(dev)) == -1) {
	perror("seropen");
	exit(2);
    }
    boot(ser, core, m, TOPCORE);
    close(ser);

    return 0;
}

int boot(int ser, unsigned char *core, int n, int off)
{
    int i, j, k, m, y;
    unsigned char c, d, *p, *q;
    unsigned short cs;
    static int x[8];
    static unsigned char v[8], z[128];

    c = 0;
    for (;;) {
	write(ser, &c, 1);
	if (nbread(ser, &d, 1, 0) == 1 && d == 0)
	    break;
    }
    c = 0x55;
    write(ser, &c, 1);
    read(ser, &d, 1);
    if (d != 0xAA)
	return 0;
    c = (n >> 8) & 0xFF;
    write(ser, &c, 1);
    c = n & 0xFF;
    write(ser, &c, 1);
    read(ser, &d, 1);
    i = (int)d << 8;
    read(ser, &d, 1);
    i += d;
    if (i != n)
	return 0;

    for (p=core, i=0; i < n;) {
	memset(z, 0, sizeof z);
	m = n - i;
	if (m > 128)
	    m = 128;
	for (q=z, j=0; j < m; j++)
	    *q++ = *p++;
	memset(x, 0, sizeof x);
	for (q=z, j=0; j < 16; j++) {
	    printf("%08X ", off+i);
	    for (y=k=0; k < 8; k++, i++) {
		if (i >= n) {
		    v[k] = ' ';
		    printf("   ");
		    continue;
		}
		c = *q++;

		write(ser, &c, 1);
		read(ser, &d, 1);
		if (c != d) {
		    fprintf(stderr, "\nfailed to transfer.\n");
		    return i;
		}

		v[k] = isprint(c) ? c : '.';
		printf("%02X ", c);
		x[k] += c;
		y += c;
	    }
	    printf(": %02X / \"%-.8s\"\n", y & 0xFF, v);
	    if (i >= n)
		break;
	}
	printf("-------------------------------------\n    SUM: ");
	for (j=0; j < 8; j++)
	    printf("%02X ", x[j] & 0xFF);
	cs = crc(z, m);
	printf("%04X\n\n", cs);
    }

    read(ser, &d, 1);
    if (d != 0xAA) {
	fprintf(stderr, "failed to transfer.\n");
    }
    return i;
}
