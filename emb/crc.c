unsigned short crc(void *s, int n)
{
    int i, j, k;
    unsigned char c, m, *p;
    unsigned short r;

    if ((i=n) < 1)
	return 0;
    p = (unsigned char *)s;
    r = *p++;
    i--;
    r = r << 8;
    if (i < 1)
	return r;
    r |= *p++;
    i--;
    m = 0x80;
    for (; i > 0; i--)
	for (c=*p++, j=0; j < 8; j++) {
	    k = (r & 0x8000) != 0;
	    r = r << 1;
	    if (c & m)
		r++;
	    if (k)
		r ^= 0x1021;
	    if (!(m >>= 1))
		m = 0x80;
	}
    return r;
}
