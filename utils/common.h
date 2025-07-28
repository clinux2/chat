#ifndef COMMON_H
#define COMMON_H

#define MAX_NAME_LEN 32     // usernames like "alice", "bob", etc.
#define MAX_CONTENT_LEN 1024 // message content

typedef struct Message {
    uint32_t conv_id;
    char from[MAX_NAME_LEN];
    char content[MAX_CONTENT_LEN];
} MSG;

#endif