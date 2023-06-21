PROG= h8boot1
OBJS= main.o

CFLAGS+= -Wall -I../emb -g
LDADD+= -L../emb -lemb -g

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDADD)

clean:
	rm -f $(PROG) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<
