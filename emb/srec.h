#ifndef __SREC_H__
#define __SREC_H__

#include <sys/types.h>

char *srec_read_line(char *s, size_t n, FILE *fp);
int srec_parse(char *s, u_char *d, size_t n);
int isxnum(char *s, size_t n);
unsigned long gethex(char *s, size_t n);

extern char *fname;
extern int line;

#endif
