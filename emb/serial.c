#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ebuf[512];

int seropen(char *dev)
{
    int fd;
    struct termios opt;

    fd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
	sprintf(ebuf, "unable to open (%s)", dev);
	perror(ebuf);
	return -1;
    }
    fcntl(fd, F_SETFL, 0);
    //opt.c_cflag = opt.c_iflag = opt.c_lflag = opt.c_iflag = 0;
    opt.c_cflag = opt.c_lflag = opt.c_iflag = 0;
    cfsetispeed(&opt, B19200);
    cfsetospeed(&opt, B19200);
    opt.c_cflag |= CS8 | CLOCAL | CREAD;
    opt.c_cc[VMIN] = 1;
    opt.c_cc[VTIME] = 0;
    tcsetattr(fd, TCSANOW, &opt);
    return fd;
}

int nbread(int fd, void *buf, int n, long msec)
{
    int r;
    ssize_t l, m = 0;
    struct timeval timeout;
    fd_set readfds;
    unsigned char *p;

    timeout.tv_sec = msec / 1000;
    timeout.tv_usec = (int)((msec - timeout.tv_sec * 1000) * 1000);
    for (l=0, p=buf; n > 0; p+=m, l+=m, n-=m) {
	FD_ZERO(&readfds);
	FD_SET(fd, &readfds);
	r = select(fd + 1, &readfds, NULL, NULL, &timeout);
	if (r == 0)
	    break;
	if (r != -1 && FD_ISSET(fd, &readfds))
	    m = read(fd, p, (size_t)n);
    }
    return l;
}
