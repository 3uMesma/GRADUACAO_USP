#ifndef ITEM_H
    #define ITEM_H

    typedef struct item ITEM;
    typedef int ITEM_TIPO;

    ITEM *item_create(ITEM_TIPO i);
    void item_free(ITEM **i);
    ITEM_TIPO item_get_valor(ITEM *i);
    ITEM *item_copy(ITEM *i);
    int item_compare(ITEM *i1, ITEM *i2);

#endif