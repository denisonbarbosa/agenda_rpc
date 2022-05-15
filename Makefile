CC=gcc
FLAGS=-I/usr/include/tirpc -ltirpc
COMMON=rbd_xdr.c Contact.c Contact.h

all: client server

client:
	$(CC) -o client rbd_client.c rbd_clnt.c $(COMMON) $(FLAGS)

server:
	$(CC) -o server rbd_server.c rbd_svc.c Contacts.c $(COMMON) $(FLAGS)

clean:
	rm client server