#ifndef _HASHMAP_H
#define _HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DEFAULT_SIZE 50
#define RESIZE_AT_PERCENT 70

typedef struct node{
    char* key;
    int value;
} node;

typedef struct hashmap{
    node** nodes;
    int size;
    int count;
} hashmap;

static inline unsigned rol(unsigned r, uint32_t k) {return (r << k) | (r >> (32 - k));}

hashmap* init_hashmap();
int destruct_hashmap(hashmap* map);
uint32_t hash(char const *input);
int insert_hashmap(hashmap* map, char const* key, int value);
int hashmap_get_value(hashmap* map, char const* key);

#endif
