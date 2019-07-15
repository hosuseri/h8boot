#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flash.h"
#include "hd.h"
#include "serial.h"

unsigned long ebtbl[] = {
    0x00000000,
    0x00000400,
    0x00000800,
    0x00000C00,
    0x00001000,
    0x00008000
};

struct block *root;

int boot(int ser)
{
    int i, j;
    unsigned char c, d;
    struct block *b;
    unsigned short cs;

    for (i=0, b=root; b != NULL; b = b->next) {
	c = 'T';
	write(ser, &c, 1);
	write(ser, &c, 1);
	c = (b->addr >> 8) & 0xFF;
	write(ser, &c, 1);
	c = b->addr & 0xFF;
	write(ser, &c, 1);
	read(ser, &c, 1);
	read(ser, &d, 1);
	if (c != ((b->addr >> 8) & 0xFF) || d != (b->addr & 0xFF)) {
	    fprintf(stderr, "bad address.\n");
	    return i;
	}
	j = write(ser, b->core, 128);
	if (j != 128) {
	    perror("write");
	    return i;
	}
	i += j;
	read(ser, &c, 1);
	read(ser, &d, 1);
	cs = hexdump(b->core, 128, b->addr);
	putchar('\n');
	fflush(stdout);
	if (c != ((cs >> 8) & 0xFF) || d != (cs & 0xFF)) {
	    fprintf(stderr, "bad CRC.\n");
	    return i;
	}
	
	c = 'F';
	write(ser, &c, 1);
	write(ser, &c, 1);
	read(ser, &c, 1);
	read(ser, &d, 1);
	if (c != ((cs >> 8) & 0xFF) || d != (cs & 0xFF)) {
	    fprintf(stderr, "bad CRC.\n");
	    return i;
	}

    }
    return i;
}

int ebdet()
{
    int i, n, r, w;
    struct block *b;

    n = sizeof(ebtbl) / sizeof(ebtbl[0]) - 1;
    r = 0;
    b = root;
    for (w=1, i=1; b != NULL && i <= n; i++, w <<= 1) {
	if (b->addr >= ebtbl[i])
	    continue;
	r |= w;
	for (; b != NULL; b = b->next)
	    if (b->addr >= ebtbl[i])
		break;
    }
    return r;
}

struct block *obtain(unsigned long addr)
{
    struct block *p, **q;

    for (p=root; p != NULL; p = p->next)
	if (addr >= p->addr && addr < p->addr + sizeof(p->core))
	    return p;
    if ((p = (struct block *)malloc(sizeof(struct block))) == NULL)
	return NULL;
    p->addr = addr & 0xFFFFFF80;
    memset(p->core, 0xFF, 128);
    for (q = &root; *q != NULL; q = &(*q)->next)
	if ((*q)->addr > p->addr)
	    break;
    p->next = *q;
    *q = p;
    return p;
}

void dump()
{
    struct block *p;

    for (p=root; p != NULL; p=p->next) {
	hexdump(p->core, 128, p->addr);
	putchar('\n');
    }
}

void freeall()
{
    struct block *p, *q;

    for (p=root; p != NULL; p=q) {
	q = p->next;
	free(p);
    }
}
