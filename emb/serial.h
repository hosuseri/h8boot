#ifndef __SERIAL_H__
#define __SERIAL_H__

int seropen(char *dev);
int nbread(int fd, void *buf, int n, long msec);

#endif
