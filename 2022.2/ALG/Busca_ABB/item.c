#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct _item {
	elem valor;
};

ITEM *item_criar(elem x) {
	ITEM *p = (ITEM *)malloc(sizeof(ITEM));
	if(p != NULL) {
		p -> valor = x;
		return p;
	}
	return NULL;
}

void set_valor(ITEM *e, elem x) {
	if(e != NULL) {
		e->valor = x;
	}
}

elem get_valor(ITEM *e) {
	if(e != NULL) {
		return e->valor;
	}
	exit(1); 
}

void apagar_item(ITEM **e) {
	if(e != NULL && *e != NULL) {
		free(*e);
		*e = NULL;
	}	
}