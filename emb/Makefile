LIB= libemb.a
OBJS= crc.o hd.o serial.o srec.o

CFLAGS+=-Wall -O0 -g
LDADD+=-g

$(LIB): $(OBJS)
	$(AR) r $(LIB) $(OBJS)
	ranlib $(LIB)

clean:
	rm -f $(LIB)
	rm -f $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<
