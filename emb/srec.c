#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "srec.h"

char *fname;
int line;

char *srec_read_line(char *s, size_t n, FILE *fp)
{
    register char *p;

    if (fgets(s, (int)n, fp) == NULL)
	return NULL;

    for (p = s + strlen(s) - 1; p > s; *p-- = '\0')
	if (*p != '\r' && *p != '\n')
	    break;
    return s;
}

int srec_parse(char *s, u_char *d, size_t n)
{
    size_t i, j, k;
    char *p;
    u_char *q, t, x;
    u_long u;

    if (n < sizeof(unsigned long)) {
	fprintf(stderr, "buffer size must be at least %ld bytes.\n",
		sizeof(unsigned long));
	return 0;
    }
    p = s;
    if (*p++ != 'S') {
	fprintf(stderr, "%s(%d): invalid format.\n", fname, line);
	return 0;
    }
    switch (t = *p++) {
    case '0':
	return 0;

    case '1':
	j = 4;
	break;

    case '2':
	j = 6;
	break;

    case '3':
	j = 8;
	break;

    case '9':
	return 0;

    default:
	fprintf(stderr, "%s(%d): unsupported format. (%c)\n",
		fname, line, t);
	return 0;
    }
    if (!isxnum(p, 2)) {
	fprintf(stderr, "%s(%d): invalid length field.\n", fname, line);
	return 0;
    }
    x = k = gethex(p, 2);
    p += 2;
    k <<= 1;
    if (strlen(p) != k) {
	fprintf(stderr, "%s(%d): invalid length.\n", fname, line);
	return 0;
    }
    k >>= 1;
    --k;  // for checksum
    if (k > n - sizeof(unsigned long)) {
	fprintf(stderr, "%s(%d): buffer is too least.\n", fname, line);
	return 0;
    }
    if (!isxnum(p, j)) {
	fprintf(stderr, "%s(%d): invalid address field. \n", fname, line);
	return 0;
    }
    u = gethex(p, j);
    p += j;
    q = d;
    j >>= 1;
    k -= j;
    for (i=0; i < sizeof(u_long); i++) {
	t = i < j ? (u_char)(u & 0xFF) : (u_char)0;
	*q++ = t;
	u >>= 8;
	x += t;
    }
    for (i=0; i < k; i++, p+=2) {
	if (!isxnum(p, 2)) {
	    fprintf(stderr, "%s(%d): invalid data field. \n", fname, line);
	    return 0;
	}
	t = (unsigned char)gethex(p, 2);
	*q++ = t;
	x += t;
    }
    if (!isxnum(p, 2)) {
	fprintf(stderr, "%s(%d): invalid checksum field. \n", fname, line);
	return 0;
    }
    t = (u_char)gethex(p, 2);
    if (t != (u_char)~x) {
	fprintf(stderr, "%s(%d): checksum error. \n", fname, line);
	return 0;
    }
    return k;
}

int isxnum(char *s, size_t n)
{
    register int i;
    register char *p;

    for (p=s, i=0; i < n; i++, p++)
	if (!isxdigit((int)*p))
	    return 0;
    return 1;
}

unsigned long gethex(char *s, size_t n)
{
    register int i;
    register unsigned long r;
    register char *p;

    for (r=0, p=s, i=0; i < n; i++, p++) {
	r <<= 4;
	if (*p >= '0' && *p <= '9')
	    r += *p - '0';
	else if (*p >= 'a' && *p <= 'f')
	    r += *p - 'a' + 10;
	else if (*p >= 'A' && *p <= 'F')
	    r += *p - 'A' + 10;
    }
    return r;
}

