all: client server

client:
	gcc -o client rbd_client.c rbd_clnt.c rbd_xdr.c Contact.c Contact.h $(FLAGS)