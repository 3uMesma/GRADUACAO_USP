#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
    
int main(int argc, char *argv[]){
  ABB *T;
  int n, m, x, op;
  
  T = abb_criar();

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    ITEM *item = item_criar(x);
    abb_inserir(T, item);
    //abb_imprimir(T);
  }

  while(m--){
    scanf("%d", &op);

    switch(op){
      case 1: { //Busca
        int num;
        scanf("%d", &num);

        if(abb_busca(T, num) != NULL) printf("Item encontrado.\n");
        else printf("Item não encontrado.\n");
        
        break;
    }
      case 2: { //Remoção
        int num;
        scanf("%d", &num);
      
        if(abb_remover(T,num)) printf("Item removido.\n");
        else printf("Item não removido.\n");
        //abb_imprimir(T);
      
        break;
      }
    }
  }
  
  abb_apagar(&T);

  return 0;
}
