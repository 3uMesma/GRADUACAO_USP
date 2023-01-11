#include <stdio.h>
# include <stdlib.h>

int compara(const void *n, const void *m){
  // basta fazer uma subtracao para saber se os numeros sao diferentes
  return ( *(int*)n - *(int*)m );
}

int busca_sequencial(int vetor[], int procurado, int i, int qtd){
  // a busca sequencial eh feitra analisando cada elemento do vetor
  
  // fazendo a condicao de parada
  if (i > qtd){
    printf("Nao encontrou\n");
    return -1;
  }
  else if (vetor[i] == procurado){
    printf("Encontrou\n");
    return 0;
  }
  return busca_sequencial(vetor, procurado, i + 1, qtd);
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
    busca_sequencial(vetor, procurado, 0, qtd);
  }
}
