#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   char str_sequencia[300];
   int qtd=0;
   
   /*qtd de sequencias a serem lidas e analisadas*/
   scanf("%d", &qtd);

   for(int i=0; i<qtd; i++){
      scanf("%s", str_sequencia);
      if(balanceada(str_sequencia))
      	printf("BALANCEADO\n");
      else
      	printf("NÃO BALANCEADO\n");
   }    
   return 0;
   
}


