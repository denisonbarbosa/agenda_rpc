#include "Contacts.h"

#include "Contact.h"

#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 128

static int num_entries = 0;
static ContactEntry *entries[MAX_ENTRIES];

/// Searches a ContactEntry by name and returns its index. If none is found,
/// returns -1.
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

  return 1;
}

SearchResult Search(char *name) {
  printf("Searching %s... ", name);
  int index = FindIndexByName(name);
  SearchResult res = {.entry = NULL, .found = FALSE};

  if (index != -1) {
    printf("Found!\n");
    res.entry = entries[index];
    res.found = TRUE;
  } else {
    printf("Not found\n");
  }

  return res;
}

int Remove(const char *name) {
  int index = FindIndexByName(name);

  if (index == -1) {
    return 0;
  }

  free_contact(&entries[index]);
  if (num_entries > 1) {
    entries[index] = entries[num_entries - 1];
    entries[num_entries - 1] = NULL;
  }

  num_entries--;
  return 1;
}
