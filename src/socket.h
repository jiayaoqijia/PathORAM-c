//
// Created by jyjia on 2016/4/29.
//

#ifndef PATHORAM_SOCKET_H
#define PATHORAM_SOCKET_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "bucket.h"



typedef enum {
    SOCKET_READ_BUCKET = 0,
    SOCKET_WRITE_BUCKET = 1,
    SOCKET_GET_META = 2,
    SOCKET_READ_BLOCK = 3,
    SOCKET_INIT = 4
} socket_type;

typedef struct {
    socket_type type;
    unsigned char buf[];
} socket_ctx;

typedef struct {
    int bucket_id;
    oram_bucket bucket;
} socket_write_bucket;

typedef struct {
    int bucket_id;
} socket_read_bucket;

typedef struct {
    int bucket_id;
    oram_bucket bucket;
} socket_read_bucket_r;

typedef struct {
    int pos;
} socket_get_metadata;

typedef struct {
    int pos;
    oram_bucket_encrypted_metadata metadata[ORAM_TREE_DEPTH];
} socket_get_metadata_r;

typedef struct {
    int pos;
    int offsets[ORAM_TREE_DEPTH];
} socket_read_block;

typedef struct {
    int pos;
    unsigned char data[ORAM_CRYPT_DATA_SIZE];
} socket_read_block_r;

typedef struct {
    int size;
} socket_init;

#define ORAM_SOCKET_READ_SIZE sizeof(socket_read_bucket) + sizeof(int)
#define ORAM_SOCKET_META_SIZE sizeof(socket_get_metadata) + sizeof(int)
#define ORAM_SOCKET_BLOCK_SIZE sizeof(socket_read_block) + sizeof(int)
#define ORAM_SOCKET_WRITE_SIZE sizeof(socket_write_bucket) + sizeof(int)

#define ORAM_SOCKET_READ_SIZE_R sizeof(socket_read_bucket_r) + sizeof(int)
#define ORAM_SOCKET_META_SIZE_R sizeof(socket_get_metadata_r) + sizeof(int)
#define ORAM_SOCKET_BLOCK_SIZE_R sizeof(socket_read_block_r) + sizeof(int)
#define ORAM_SOCKET_INIT_SIZE sizeof(socket_init) + sizeof(int)

#define ORAM_SOCKET_BUFFER ORAM_SOCKET_READ_SIZE_R

#define ORAM_SOCKET_BACKLOG 40

void sock_init(struct sockaddr_in *addr, socklen_t *addrlen, int *sock,
                 char *host, int port, int if_bind);
#endif //PATHORAM_SOCKET_H
