#include <stdio.h>
#include "hashmap.h"

int main(){
    hashmap* map;
    map = init_hashmap(map);
    
    if(map == NULL)
        return 1;
    
    insert_hashmap(map, "tst", 10);
    insert_hashmap(map, "tst2", 20);
    insert_hashmap(map, "tst3", 30);
   
    printf("%d\n", hashmap_get_value(map, "tst")); 
    printf("%d\n", hashmap_get_value(map, "tst2")); 
    printf("%d\n", hashmap_get_value(map, "tst3")); 

    destruct_hashmap(map);

    return 0;
}
