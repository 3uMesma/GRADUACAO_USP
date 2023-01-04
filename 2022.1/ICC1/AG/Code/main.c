#include <stdio.h>
#include "sort.h"

int main(){
  srand(time(NULL));
  // leitura dos dados:
  int *constantes = ler_const();
  int tam;
  printf("Tamanho da populacao: ");
  scanf("%d", &tam);
  double mutacao;
  printf("Digite o fator da mutação: ");
  scanf("%lf", &mutacao);
  int geracao_max;
  printf("Digite o numero maximo de geracoes: ");
  scanf("%d", &geracao_max);

  // inicio do processo:
  CANDIDATO *geracao = (CANDIDATO*) malloc (tam * sizeof(CANDIDATO));
  aleatorios(tam, geracao);

  int geracao_atual = 1;
  while (geracao_atual <= geracao_max){
    printf("Geracao atual = %d\n", geracao_atual);
    calcular_fitness(tam, geracao, constantes);
    // se jah encontrar o numero ideal o programa para
    if (candidato_ideal(geracao, tam) == true)break;
    quickSort(geracao, 0, tam - 1);
    imprimir_vetor(geracao, tam);
    melhores(geracao, tam, mutacao);
    printf("==========================================================\n");
    geracao_atual++;
  }
  // se nao encontrou o numero perfeito, colocar o mais proximo do resultado ideal
  printf("\tVENCEDOR:\n");
  printf("Numero: %d\n", geracao[0].numero);
  printf("Fitness: %d\n", geracao[0].fitness);
}
