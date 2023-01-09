#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(int argc, char *argv[]){ 
    int n, m, num;

    LISTA *lista = lista_criar();

    scanf("%d", &n);

    while(n--){
        scanf("%d", &num);
        ITEM *item = item_criar(num);

        lista_inserir(lista, item);
    }

    lista_inverter(&lista);
    lista_imprimir(lista);
    lista_apagar(&lista);
   	
    return (0);
}


