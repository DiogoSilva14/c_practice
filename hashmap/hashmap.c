#include "hashmap.h"

uint32_t hash(char const* input) { 
    uint32_t result = 0x55555555;

    while (*input) { 
        result ^= *input++;
        result = rol(result, 5);
    }

    return result;
}

hashmap* init_hashmap(){
    hashmap* map = malloc(sizeof(hashmap));

    if(map == NULL) 
        return NULL;

    memset(map, 0, sizeof(hashmap));

    map->nodes = malloc(sizeof(node*) * DEFAULT_SIZE);

    if(map->nodes == NULL)
        return NULL;

    memset(map->nodes, 0, sizeof(node*) * DEFAULT_SIZE);

    map->size = DEFAULT_SIZE;
    map->count = 0;

    return map;
}

int insert_hashmap(hashmap* map, char const* key, int value){
    if(map == NULL)
        return 1;
    /*
       if(map->count > map->size*RESIZE_AT_PERCENT){
       int res = realloc(map->nodes, (map->size + DEFAULT_SIZE) * sizeof(node*));

       if(res)
       return 1;

       for(int i=0; i < map->size; i++){

       }

       map->size += DEFAULT_SIZE;


       }
       */

    uint32_t pos = hash(key) % map->size;

    if(map->nodes[pos] != NULL){
        printf("Already ocuppied\n");
    }

    map->nodes[pos] = malloc(sizeof(node*));

    if(map->nodes[pos] == NULL)
        return 1;

    map->nodes[pos]->key = malloc(sizeof(char)*(strlen(key) + 1));
    strcpy(map->nodes[pos]->key, key);

    map->nodes[pos]->value = value;

    return 0;
}

int hashmap_get_value(hashmap* map, char const* key){
    if(map == NULL)
        return 1;

    uint32_t pos = hash(key) % map->size;

    if(hash(key) == hash(map->nodes[pos]->key)){
        return map->nodes[pos]->value;
    }

    return 0;
}

int destruct_hashmap(hashmap* map){
    if(map->size)
        goto free_map;

    for(int i=0; i < map->size; i++){ 
        if(map->nodes[i] != NULL)
            free(map->nodes[i]);
    }

free_map:
    free(map);

    return 0;
}
