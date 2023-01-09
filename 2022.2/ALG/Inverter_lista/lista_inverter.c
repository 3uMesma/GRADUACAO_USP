#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

bool lista_inverter(LISTA **lista){
  // testando se a lista está vazia:
  if (lista == NULL){
    return false;
  }
  
  NO* anterior = NULL;
  NO* atual = (*lista) -> inicio;
  
  // percorre a lista
  while (atual != NULL){
    NO* proximo = atual -> proximo;
    atual -> proximo = anterior;
    // avança os dois ponteiros
    anterior = atual;
    atual = proximo;
    }
  
  // corrige o ponteiro do final
  (*lista) -> inicio = anterior;
  return true;
}