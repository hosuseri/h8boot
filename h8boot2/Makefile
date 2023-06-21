PROG= h8boot2
OBJS= main.o flash.o

CFLAGS+= -Wall -I../emb -O0 -g
LDADD+= -L../emb -lemb -g

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDADD)

clean:
	rm -f $(PROG) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<
