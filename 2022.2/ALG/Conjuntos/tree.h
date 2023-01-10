#ifndef TREE_H
    #define TREE_H
    #include <stdbool.h>
    #include "item.h"
    typedef struct tree TREE;
    typedef ITEM DATA;
    TREE *tree_create(DATA *ref);
    void tree_free(TREE **remove,bool remove_items);
    int data_compara(DATA *a,DATA *b);
    bool tree_contains(TREE *raiz,DATA *item);
    bool tree_inserir(TREE **sn,DATA *toadd);
    void tree_print(TREE *sn);
    void tree_print_nonspace(TREE *sn);
    void tree_remove(TREE **raiz,DATA *toremove);
    TREE *tree_copy(TREE *t);
    TREE *tree_merge(TREE *a, TREE *b);
    TREE *tree_union(TREE *a, TREE *b);
#endif