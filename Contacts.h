/// The contact list.

#ifndef CONTACTS_H
#define CONTACTS_H

#include "rbd.h"

int Insert(const ContactEntry *contact);
SearchResult Search(char *name);
int Remove(const char *name);

#endif