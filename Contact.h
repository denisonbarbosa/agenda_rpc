#ifndef AGENDA_RPC_CONTACT_H
#define AGENDA_RPC_CONTACT_H

#include "rbd.h"

ContactEntry *new_contact() ;
ContactEntry* copy_contact(const ContactEntry* contact);
void free_contact(ContactEntry **ptr) ;

#endif
