#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hd.h"
#include "crc.h"

unsigned short hexdump(void *s, int n, unsigned long off)
{
    int c, i, j, k, m, y;
    unsigned char *p, *q;
    unsigned short cs = 0;
    static int x[8];
    static unsigned char v[8], z[128];

    for (p=s, i=0; i < n;) {
	memset(z, 0, sizeof z);
	m = n - i;
	if (m > 128)
	    m = 128;
	for (q=z, j=0; j < m; j++)
	    *q++ = *p++;
	memset(x, 0, sizeof x);
	for (q=z, j=0; j < 16; j++) {
	    printf("%08lX ", off+i);
	    for (y=k=0; k < 8; k++, i++) {
		if (i >= n) {
		    v[k] = ' ';
		    printf("   ");
		    continue;
		}
		c = *q++;
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
	printf("%04X\n", cs);
    }
    return cs;
}
