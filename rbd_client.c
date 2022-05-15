#include "rbd.h"

#include "Contact.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
  printf(" 1) New contact\n"
         " 2) Search contact\n"
         " 3) Remove contact\n"
         " 4) Exit\n");
}

void create_contact(CLIENT *client) {
  ContactEntry contact = {NULL, NULL, NULL, NULL};
  size_t size;

  printf("Name: ");
  getline(&contact.name, &size, stdin);
  contact.name[strlen(contact.name) - 1] = '\0';

  printf("Phone: ");
  getline(&contact.phone, &size, stdin);
  contact.phone[strlen(contact.phone) - 1] = '\0';

  printf("Address: ");
  getline(&contact.address, &size, stdin);
  contact.address[strlen(contact.address) - 1] = '\0';

  printf("Email: ");
  getline(&contact.email, &size, stdin);
  contact.address[strlen(contact.address) - 1] = '\0';

  int *result = insert_1(&contact, client);

  if (result)
    printf("Success!\n");
  else
    printf("Something went wrong\n");

  free(contact.name);
  free(contact.phone);
  free(contact.address);
  free(contact.email);
}

void search_contact(CLIENT *client) {
  char *name = NULL;
  size_t size;

  printf("Name: ");
  getline(&name, &size, stdin);
  name[strlen(name) - 1] = '\0';

  SearchResult *result = search_1(&name, client);

  if (result) {
    if (result->found) {
      printf("Contact info:\n"
             "Name: %s\n"
             "Phone: %s\n"
             "Address: %s\n"
             "Email: %s\n",
             result->entry->name, result->entry->phone, result->entry->address,
             result->entry->email);
    } else {
      printf("Contact not found\n");
    }
  } else {
    printf("Something went wrong\n");
  }

  free(name);
}

void remove_contact(CLIENT *client) {
  char *name = NULL;
  size_t size;

  printf("Name: ");
  getline(&name, &size, stdin);
  name[strlen(name) - 1] = '\0';

  int *result = remove_1(&name, client);

  if (result) {
    if (*result == 1) {
      printf("Success!\n");
    } else {
      printf("Contact not found.\n");
    }
  } else {
    printf("Something went wrong\n");
  }

  free(name);
}

void rbdprog_1(char *host) {
  CLIENT *clnt;
  ContactEntry *insert_1_arg = new_contact();
  char quit;

#ifndef DEBUG
  clnt = clnt_create(host, RBDPROG, RDBVERS, "tcp");
  if (clnt == NULL) {
    clnt_pcreateerror(host);
    exit(1);
  }
#endif /* DEBUG */

  printf("RPC Contacts\n");

  char *input = NULL;
  size_t size = 0;
  while (TRUE) {
    print_menu();

    getline(&input, &size, stdin);
    long option = strtol(input, NULL, 10);

    switch (option) {
    case 1:
      create_contact(clnt);
      break;
    case 2:
      search_contact(clnt);
      break;
    case 3:
      remove_contact(clnt);
      break;
    case 4:
      printf("Are you sure you want to quit? (y/N)\n");
      scanf(" %c", &quit);
      if (quit == 'y') {
        free_contact(&insert_1_arg);
        clnt_destroy(clnt);
        exit(0);
      }
      break;
    default:
      printf("Invalid option\n");
    }
  }

#ifndef DEBUG
  clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char *argv[]) {
  char *host;

  if (argc < 2) {
    printf("usage: %s server_host\n", argv[0]);
    exit(1);
  }
  host = argv[1];
  rbdprog_1(host);
  exit(0);
}
