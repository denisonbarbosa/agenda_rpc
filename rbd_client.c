#include "rbd.h"

#include "Contact.h"

#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    printf(
        " 1) New contact\n"
        " 2) Search contact\n"
        " 3) Remove contact\n"
        " 4) Exit\n");
}

void rbdprog_1(char *host)
{
    CLIENT *clnt;
    int option;
    ContactEntry *insert_1_arg = new_contact();
    char *remove_1_arg = malloc(32 * sizeof(char));
    char *search_1_arg = malloc(32 * sizeof(char));
    SearchResult *search_result;
    int *result;
    char quit;

#ifndef DEBUG
    clnt = clnt_create(host, RBDPROG, RDBVERS, "tcp");
    if (clnt == NULL)
    {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif /* DEBUG */

    printf("RPC Contacts\n");

    while (TRUE)
    {
        print_menu();
        scanf(" %d", &option);

        switch (option)
        {
        case 1:
            printf("Format: {name} {phone} {address} {email}\n");
            scanf("%s %s %s %s",
                  insert_1_arg->name,
                  insert_1_arg->phone,
                  insert_1_arg->address,
                  insert_1_arg->email);
            result = insert_1(insert_1_arg, clnt);

            if (result)
                printf("Success!\n");
            else
                printf("Something went wrong\n");

            break;
        case 2:
            printf("Input the name of the desired contact\n");
            scanf(" %s", search_1_arg);
            search_result = search_1(&search_1_arg, clnt);
            if (search_result->found == FALSE)
            {
                printf("Contact not found\n");
                continue;
            }
            else
            {
                printf("Contact: %s %s %s %s\n",
                       search_result->entry->name,
                       search_result->entry->phone,
                       search_result->entry->address,
                       search_result->entry->email);
            }
            break;
        case 3:
            printf("Input the name of the contact to be deleted\n");
            scanf("%s", remove_1_arg);
            result = remove_1(&remove_1_arg, clnt);

            if (result)
                printf("Success!\n");
            else
                printf("Something went wrong\n");

            break;
        case 4:
            printf("Are you sure you want to quit? (y/N)\n");
            scanf(" %c", &quit);
            if (quit == 'y')
            {
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

int main(int argc, char *argv[])
{
    char *host;

    if (argc < 2)
    {
        printf("usage: %s server_host\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    rbdprog_1(host);
    exit(0);
}
