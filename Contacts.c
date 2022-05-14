#include "Contacts.h"

#define MAX_ENTRIES 128

#include "Contact.h"

static int num_entries = 0;
static ContactEntry *entries[MAX_ENTRIES];

/// Searches a ContactEntry by name and returns its index. If none is found, returns -1.
static int FindIndexByName(const char *name) {
    for (int i = 0; i < num_entries; ++i) {
        if (strcmp(name, entries[i]->name) == 0) {
            return i;
        }
    }

    return -1;
}

int Insert(const ContactEntry *contact) {
    printf("Creating contact %s\n", contact->name);

    entries[num_entries] = copy_contact(contact);
    num_entries++;

    printf("CONTATOS ATÉ AGORA:\n");
    for (int i = 0; i < num_entries; ++i) {
        printf("%s %s %s %s\n", entries[i]->name, entries[i]->phone, entries[i]->address, entries[i]->email);
    }

    return 1;
}

ContactEntry *Search(char *name) {
    printf("Searching %s\n", name);
    int index = FindIndexByName(name);
    printf("Found contact at index %d\n", index);
    if (index != -1) {
        printf("Contact: %s %s %s %s\n", entries[index]->name, entries[index]->phone, entries[index]->email,
               entries[index]->address);
        return entries[index];
    }
    return NULL;
}


int Remove(const char *name) {
    int index = FindIndexByName(name);

    if (index == -1) {
        return 0;
    }

    free_contact(&entries[index]);
    if (num_entries > 1) {
        entries[index] = entries[num_entries - 1];
    }

    num_entries--;
    return 1;
}
