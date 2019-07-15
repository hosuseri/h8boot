#include "3694S.h"

long usleep(short n);  /* 46T + n * 10T */
void putuc(unsigned char uc);
unsigned char getuc();
short sci_read(unsigned char *buf, short n);
unsigned short crc(void *s, short n);
short flash();
void burn(short t);

unsigned char *addr;
unsigned char buf[128], re[128], sup[128];

int main()
{
    unsigned char c, d;
    unsigned short cs;

    SCI3.SCR3.BYTE = 0;
    IO.PMR1.BIT.TXD = 1;
    SCI3.SCR3.BIT.TE = 1;
    SCI3.SCR3.BIT.RE = 1;
    for (;;) {
	c = getuc();
	d = getuc();
	if (c != d)
	    continue;
	switch (c) {
	case 'T':
	    c = getuc();
	    d = getuc();
	    addr = (unsigned char *)0 + ((c << 8) | d);
	    putuc(c);
	    putuc(d);
	    sci_read(buf, 128);
	    cs = crc(buf, 128);
	    putuc((cs >> 8) & 0xFF);
	    putuc(cs & 0xFF);
	    break;

	case 'F':
	    flash();
	    cs = crc(addr, 128);
	    putuc((cs >> 8) & 0xFF);
	    putuc(cs & 0xFF);
	    break;

	default:
	    break;
	}
    }

    return 0;
}

void putuc(unsigned char uc)
{
    for (;;)
	if (SCI3.SSR.BIT.TDRE)
	    break;
    SCI3.TDR = uc;
    while (!SCI3.SSR.BIT.TEND)
	;
}

unsigned char getuc()
{
    for (;;)
	if (SCI3.SSR.BIT.RDRF)
	    break;
    return SCI3.RDR;
}


short sci_read(unsigned char *buf, short n)
{
    register short i, j;
    register unsigned char *p;

    for (p=buf, j=i=0; i < n; i++) {
	for (;;)
	    if (SCI3.SSR.BIT.RDRF)
		break;
	*p = SCI3.RDR;
	j += *p++;
    }
    return j;
}

unsigned short crc(void *s, short n)
{
    short i, j, k;
    unsigned char c, m, *p;
    unsigned short r;

    if ((i=n) < 1)
	return 0;
    p = (unsigned char *)s;
    r = *p++;
    i--;
    r <<= 8;
    if (i < 1)
	return r;
    r |= *p++;
    i--;
    m = 0x80;
    for (; i > 0; i--)
	for (c=*p++, j=0; j < 8; j++) {
	    k = (r & 0x8000) != 0;
	    r <<= 1;
	    if (c & m)
		r++;
	    if (k)
		r ^= 0x1021;
	    if (!(m >>= 1))
		m = 0x80;
	}
    return r;
}

short flash()
{
    short i, m, n;
    unsigned char c, *s, *p, *q;
    volatile unsigned char *d;

    FLASH.FLMCR1.BIT.SWE = 1;
    usleep(1);  /* 1us */
    for (p=re, q=buf, i=0; i < 128; i++)
	*p++ = *q++;
    for (n=1; n <= 1000; n++) {
	m = 0;
	for (s=re, d=addr, i=0; i < 128; i++)
	    *d++ = *s++;
	burn(n <= 6 ? 56 : 396);
	FLASH.FLMCR1.BIT.PV = 1;
	usleep(4);  /* 4us */
	p = sup;
	q = re;
	d = addr;
	for (s=buf, i=0; i < 128; i++, s++) {
	    *d = 0xFF;
	    usleep(1);  /* 2us */
	    c = *d++;
	    if (c != *s)
		m = 1;
	    if (n <= 6)
		*p = *s | c;
	    p++;
	    *q++ = *s | ~c;
	}
	FLASH.FLMCR1.BIT.PV = 0;
	usleep(1);  /* 2us */
	if (n <= 6) {
	    for (s=sup, d=addr, i=0; i < 128; i++)
		*d++ = *s++;
	    burn(16);
	}
	if (m == 0)
	    break;
    }
    FLASH.FLMCR1.BIT.SWE = 0;
    usleep(196);  /* 100us */

    return m;
}

void burn(short t)
{
    WDT.TMWD.BIT.CKS = 0xB;
    WDT.TCSRWD.BIT.B6WI = 0;
    WDT.TCSRWD.BIT.TCWE = 1;
    WDT.TCWD = 0;
    WDT.TCSRWD.BIT.B4WI = 0;
    WDT.TCSRWD.BIT.TCSRWE = 1;
    WDT.TCSRWD.BIT.B2WI = 0;
    WDT.TCSRWD.BIT.WDON = 1;
    FLASH.FLMCR1.BIT.PSU = 1;
    usleep(96);  /* 50us */
    FLASH.FLMCR1.BIT.P = 1;
    usleep(t);
    FLASH.FLMCR1.BIT.P = 0;
    usleep(6);  /* 5us */
    FLASH.FLMCR1.BIT.PSU = 0;
    usleep(6);  /* 5us */
    WDT.TCSRWD.BIT.WDON = 0;
}
