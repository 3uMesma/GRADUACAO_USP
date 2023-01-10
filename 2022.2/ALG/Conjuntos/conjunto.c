#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

struct conjunto{
    TREE *org;
};
CONJUNTO *conjunto_create(){
    CONJUNTO *c = malloc(sizeof(CONJUNTO));
    c->org = NULL;
    return c;
}
void conjunto_free(CONJUNTO **c,bool remove_items){
    if(*c==NULL){return;}
    tree_free(&((*c)->org),remove_items);
    free(*c);
    *c=NULL;
}
void conjunto_inserir(CONJUNTO *c,DATA *item){
    tree_inserir(&(c->org),item);
}
void conjunto_remover(CONJUNTO *c,DATA *item){
    tree_remove(&(c->org),item);
}
void conjunto_print(CONJUNTO *c){
    tree_print_nonspace(c->org);
}
void conjunto_print_runcodes(CONJUNTO *c){
    tree_print_nonspace(c->org);
}
bool conjunto_pertence(CONJUNTO *c,DATA *item){
    return tree_contains(c->org,item);
}
CONJUNTO *conjunto_uniao(CONJUNTO *a,CONJUNTO *b){
    CONJUNTO *c = conjunto_create();
    c->org = tree_merge(a->org,b->org);
    return c;
}
CONJUNTO *conjunto_interseccao(CONJUNTO *a,CONJUNTO *b){
    CONJUNTO *c = conjunto_create();
    c->org = tree_union(a->org,b->org);
    return c;
}
CONJUNTO *conjunto_copy(CONJUNTO *a){
    CONJUNTO *c = conjunto_create();
    c->org = tree_copy(a->org);
    return c;
}