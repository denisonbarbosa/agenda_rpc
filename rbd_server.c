#include "rbd.h"

#include "Contacts.h"

int *insert_1_svc(ContactEntry *argp, struct svc_req *rqstp) {
    static int result;
    result = Insert(argp);
    return &result;
}

int *remove_1_svc(char **argp, struct svc_req *rqstp) {
    static int result;
    result = Remove(*argp);
    return &result;
}

ContactEntry *search_1_svc(char **argp, struct svc_req *rqstp) {
    return Search(*argp);
}
