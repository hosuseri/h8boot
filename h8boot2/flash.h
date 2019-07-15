#ifndef __FLASH_H__
#define __FLASH_H__

struct block {
    struct block *next;
    unsigned long addr;
    unsigned char core[128];
};

int boot(int ser);
int ebdet();
struct block *obtain(unsigned long addr);
void dump();
void freeall();

extern struct block *root;

#endif
