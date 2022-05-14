cmake_minimum_required(VERSION 3.13)
project(agenda_rpc)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(client
        rbd_client.c
        rbd_clnt.c
        rbd_xdr.c
        Contact.c Contact.h)

add_executable(server
        rbd_svc.c
        rbd_server.c
        Contacts.c
        rbd_xdr.c
        Contact.c Contact.h)


target_link_libraries(client tirpc)
target_link_libraries(server tirpc)

target_include_directories(client PUBLIC /usr/include/tirpc)
target_include_directories(server PUBLIC /usr/include/tirpc)
