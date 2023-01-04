#include "sort.h"

void troca(CANDIDATO *a, CANDIDATO *b){
  int aux = a -> numero;
  a -> numero = b -> numero;
  b -> numero = aux;
  int aux1 = a -> fitness;
  a -> fitness = b -> fitness;
  b-> fitness = aux1;
}

int mediana(CANDIDATO *geracao, int primeiro, int ultimo){
  //procura a mediana entre inicio, meio e fim
  int meio = (primeiro + ultimo) / 2;
  int a = geracao[primeiro].fitness;
  int b = geracao[meio].fitness;
  int c = geracao[ultimo].fitness;
  
  // encontrando a mediana:
  if (a < b) {
    if (b < c) {
      //se a < b < c, o proprio meio já é a mediana:
      return meio;
    } else {
      if (a < c) {
        //se a < c && c <= b, c(ultimo) vai ser a mediana:
        return ultimo;
      } else {
        //se c <= a && a < b, a(primeiro) vai ser a mediana;
        return primeiro;
        }
      }
    } else {
      if (c < b) {
        //se c < b && b <= a, o indice vai ser b(meio):
        return meio;
      } else {
        if (c < a) {
          //se b <= c && c < a, o indice vai ser c (ultimo):
          return ultimo;
        } else {
          //se b <= a && a <= c, o indice vai ser a (primeiro):
          return primeiro;
        }
      }
    }
  }

int particao(CANDIDATO *geracao, int primeiro, int ultimo) {
  int ID_mediana = mediana(geracao, primeiro, ultimo);
  //colocando a mediana no fim pra fazer o quickSort:
  troca(&geracao[ID_mediana], &geracao[ultimo]);
        
  //o pivot é o elemento final
  int pivot = geracao[ultimo].fitness;
  int i = primeiro - 1;
  int j;
  for (j = primeiro; j < ultimo; j++) {
    if (geracao[j].fitness <= pivot) {
      i++;
      troca(&geracao[i], &geracao[j]);
    }
  }
  troca(&geracao[i + 1], &geracao[ultimo]);
  return (i + 1);
}

// função principal para o quick sort
void quickSort(CANDIDATO *geracao, int primeiro, int ultimo){
  if (primeiro < ultimo) {
    // fazendo a partição
    int parte = particao(geracao, primeiro, ultimo);
    // separadamente ordenar cada parte da partição
    quickSort(geracao, primeiro, parte - 1);
    quickSort(geracao, parte + 1, ultimo);
  }
}