#include "Contact.h"
#include <string.h>

ContactEntry *new_contact() {
    ContactEntry *ptr = malloc(sizeof(ContactEntry));
    ptr->name = malloc(32 * sizeof(char));
    ptr->phone = malloc(32 * sizeof(char));
    ptr->address = malloc(64 * sizeof(char));
    ptr->email = malloc(32 * sizeof(char));
}

void free_contact(ContactEntry **ptr) {
    free((*ptr)->name);
    free((*ptr)->phone);
    free((*ptr)->address);
    free((*ptr)->email);
    free(*ptr);
    *ptr = NULL;
}

ContactEntry* copy_contact(const ContactEntry* contact) {
    ContactEntry * ptr = new_contact();
    strcpy(ptr->name, contact->name);
    strcpy(ptr->phone, contact->phone);
    strcpy(ptr->address, contact->address);
    strcpy(ptr->email, contact->email);

    return ptr;
}
