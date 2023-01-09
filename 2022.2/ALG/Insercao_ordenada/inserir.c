#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#include "item.h"

bool lista_inserir(LISTA* lista_input, ITEM* num){
  // testando se a lista e o item estão okay
  if (lista_input == NULL || num == NULL){
    return false;
  }

  // testando se a lista está cheia:
  if (lista_input -> fim >= TAM_MAX){
    return false;
  }
  
  // encontrando a posição que o elemento deve ficar:
  int i = 0;
  int ultimo = lista_input -> fim;
  while ((ultimo != i) && item_get_chave(lista_input -> lista[i]) < item_get_chave(num)){
    i++;
  }

  // caso esteja tudo okay, aumentar o tamanho da lista:
  lista_input -> fim++;
  
  // movendo tudo pra frente:
  int tam = lista_input -> fim - 1;
  for (int j = 0; j < (tam - i); j++){
    lista_input -> lista[tam - j] = lista_input -> lista[tam - 1 - j];
  }
  // agora colocando o elemento na posição certa:
  lista_input -> lista[i] = num;
  return true;
  }