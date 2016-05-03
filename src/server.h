//
// Created by jyjia on 2016/4/29.
//

#ifndef PATHORAM_SERVER_H
#define PATHORAM_SERVER_H


#include "bucket.h"
#include "args.h"
#include "socket.h"

typedef struct {
    int socket_listen;
    int socket_data;
    struct sockaddr_in client_addr;
    socklen_t addrlen;
    struct sockaddr_in server_addr;
    int running;
    unsigned char *buff;
    unsigned char *buff_r;
} server_ctx;

void read_bucket(int bucket_id, socket_read_bucket_r *read_bucket_ctx, storage_ctx *sto_ctx);

void write_bucket(int bucket_id, oram_bucket *bucket, storage_ctx *sto_ctx);

void get_metadata(int pos, socket_get_metadata_r *meta_ctx, storage_ctx *sto_ctx);

void read_block(int pos, int offsets[], socket_read_block_r *read_block_ctx, storage_ctx *sto_ctx);

void init_server(int size, storage_ctx *sto_ctx);

void server_run(oram_args_t *args);

#endif //PATHORAM_SERVER_H
