#ifndef ITEM_H
	#define ITEM_H

  typedef int elem;
  typedef struct _item ITEM;

  ITEM *item_criar(elem x);
  void set_valor(ITEM *e, elem x);
  elem get_valor(ITEM *e);
  void apagar_item(ITEM **e);

#endif