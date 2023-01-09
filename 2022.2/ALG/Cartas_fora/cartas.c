#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void cartas (int n) {
  FILA *fila_cartas = fila_criar();
  
  // adicionando os numeros a fila
  for (int i = 1; i <= n; i++){
    ITEM *elemento =  item_criar(i);
    fila_inserir(fila_cartas, elemento);
  }

  printf("Discarded cards: ");
  
  // o menos 1 eh pq uma carta fica sobrando
  for (int i = 0; i < n - 1; i++){
    // pegando o elemento do inicio e excluindo ele
    ITEM *primeiro = fila_remover(fila_cartas);
    int imprimir_primeiro = item_get_chave(primeiro);
    printf("%d", imprimir_primeiro);
    
    // imprimindo uma virgula caso esse nao seja o ultimo elemento
    if (fila_tamanho(fila_cartas) != 1){
      printf(", ");
    }
    
    // encontrando o novo elemento do inicio e mandando ele para o final
    ITEM *novo_primeiro = fila_frente(fila_cartas);
    fila_inserir(fila_cartas, novo_primeiro);
    fila_remover(fila_cartas);
  }
  printf("\n");
  // pegando a carta que sobrou
  ITEM *sobrevivente = fila_remover(fila_cartas);
  printf("Remaining card: ");
  int imprimir_sobrevivente = item_get_chave(sobrevivente);
  printf("%d\n", imprimir_sobrevivente);
}