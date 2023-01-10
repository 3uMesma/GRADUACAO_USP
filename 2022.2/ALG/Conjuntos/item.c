#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item{
    ITEM_TIPO valor;
};


ITEM *item_create(ITEM_TIPO x){
    ITEM *i = (ITEM *)malloc(sizeof(ITEM));
    if(i != NULL){
        i->valor = x;
        return i;
    }
    return NULL;
}

void item_free(ITEM **i){
    if(i != NULL && *i != NULL){
        free(*i);
        *i = NULL;
    }
}

int item_get_valor(ITEM *i){
    if(i != NULL){
        return i->valor;
    }
}
ITEM *item_copy(ITEM *i){
    return item_create(i->valor);
}

int item_compare(ITEM *i1, ITEM *i2){
    if(i1 != NULL && i2 != NULL){
        if(i1->valor > i2->valor){
            return 1;
        } else if(i1->valor < i2->valor){
            return -1;
        } else{
            return 0;
        }
    }
}