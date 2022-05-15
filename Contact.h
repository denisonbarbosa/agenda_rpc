/// Responsible for allocating/deallocating contacts.

#ifndef CONTACT_H
#define CONTACT_H

#include "rbd.h"

ContactEntry *new_contact() ;
ContactEntry* copy_contact(const ContactEntry* contact);
void free_contact(ContactEntry **ptr) ;

#endif
