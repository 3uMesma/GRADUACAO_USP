#ifndef CONJUNTO_H
    #define CONJUNTO_H
    #include "tree.h"
    typedef struct conjunto CONJUNTO;
    CONJUNTO *conjunto_create();
    void conjunto_free(CONJUNTO **c,bool remove_items);
    void conjunto_inserir(CONJUNTO *c,DATA *item);
    void conjunto_remover(CONJUNTO *c,DATA *item);
    void conjunto_print(CONJUNTO *c);
    bool conjunto_pertence(CONJUNTO *c,DATA *item);
    CONJUNTO *conjunto_uniao(CONJUNTO *a,CONJUNTO *b);
    CONJUNTO *conjunto_interseccao(CONJUNTO *a,CONJUNTO *b);
    CONJUNTO *conjunto_copy(CONJUNTO *a);
#endif