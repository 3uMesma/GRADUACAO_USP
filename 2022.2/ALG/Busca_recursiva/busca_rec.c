#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int busca_rec(LISTA *lista, int chave){
  // caso default:
  if (lista -> inicio == NULL){
    return 0;
  }
  
  //fazendo a busca:
  int vezes = 0;
  int atual = item_get_chave(lista -> inicio -> item);
  if (atual == chave){
    vezes = 1;
  }

  // salvando o inicio:
  NO *backup_inicio = lista -> inicio;
  // mudando o incio pra buscar recursiva fucionar:
  lista -> inicio = lista -> inicio -> proximo;
  
  vezes += busca_rec(lista, chave);
  // voltando o inicio para o original:
  lista -> inicio = backup_inicio;
  return vezes;
}