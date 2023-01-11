#include <stdio.h>
# include <stdlib.h>

int compara(const void *n, const void *m){
  // basta fazer uma subtracao para saber se os numeros sao diferentes
  return ( *(int*)n - *(int*)m );
}

int busca_binaria(int vetor[], int comeco, int fim, int procurado){
  int i = (comeco + fim)/2;
  // criterio de parada da funcao recursiva
  if (comeco > fim){
    printf("Nao encontrou\n");
    return -1;
  }
      // ja encontramos o numero
  if (vetor[i] == procurado){
    printf("Encontrou\n");
    return 0;
  }
  // item estah a direita
  if (vetor[i] < procurado){
    return busca_binaria(vetor, i + 1, fim, procurado);
  }
  // item estah a esquerda
  if (vetor[i] > procurado){
    return busca_binaria(vetor, comeco, i - 1, procurado);
  }
  return 0;
}

int main(void) {
  // lendo a quantidade de itens
  int qtd;
  scanf("%d", &qtd);

  int vetor[qtd];
  for (int i = 0; i < qtd; i++){
    scanf("%d", &vetor[i]);
  }

  // ordenando antes de fazer a busca
  qsort(vetor, qtd, sizeof(int), compara);

  // buscando o numero
  int qtd_buscas;
  scanf("%d", &qtd_buscas);
  for (int i = 0; i < qtd_buscas; i++){
    int procurado;
    scanf("%d", &procurado);
    busca_binaria(vetor, 0, qtd, procurado);
  }
}
