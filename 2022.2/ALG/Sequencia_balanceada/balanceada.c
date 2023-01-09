#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"

bool balanceada(char *sequencia){
  int i = 0;

  // criando uma stack auxiliar:
  PILHA *stack_aux = pilha_criar();

  // percorrendo a string toda para fazer a verificação:
  while(sequencia[i] == '(' || sequencia[i] == ')' || sequencia[i] == '[' || sequencia[i] == ']'|| sequencia[i] == '{' || sequencia[i] == '}'){
    // se ele for um negocio de fechamento:
    if (sequencia[i] == ')' || sequencia[i] == ']' || sequencia[i] == '}'){
      
      // se a pilha estiver vazia, estamos tentando fechar algo que sequer abriu
      if (pilha_vazia(stack_aux) == 1){
        return false;
      }
      
      int aux = item_get_chave(pilha_topo(stack_aux));
      // codigo da tabela ASCII
      if (sequencia[i] == ')' && aux == 40 || sequencia[i] == ']' && aux == 91 || sequencia[i] == '}' && aux == 123){
      }
        // se o ultimo elemento da pilha tbm nao fechar o conjunto a gente ja retorna falso tbm
      else{
        return false;
      }

      // se o ultimo elemento da pilha tbm nao fechar o conjunto a gente ja retorna falso tbm
      pilha_desempilhar(stack_aux);
    }
    else{
      ITEM *novo_elemento = item_criar(sequencia[i]);
      pilha_empilhar(stack_aux, novo_elemento);
    }
    i++;
  }
  
  // se a lista estah vazia:
  if (pilha_vazia(stack_aux) == 1){
    return true;
  }
  return false;
}