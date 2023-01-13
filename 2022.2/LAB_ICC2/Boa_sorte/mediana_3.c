#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

int mediana(int *vetor, int primeiro, int ultimo){
  //procura a mediana entre inicio, meio e fim
  int meio = (primeiro + ultimo) / 2;
  int a = vetor[primeiro];
  int b = vetor[meio];
  int c = vetor[ultimo];
  
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

int particao(int *vetor, int primeiro, int ultimo) {
  int ID_mediana = mediana(vetor, primeiro, ultimo);
  //colocando a mediana no fim pra fazer o quickSort:
  troca(&vetor[ID_mediana], &vetor[ultimo]);
        
  //o pivot é o elemento final
  int pivot = vetor[ultimo];
  int i = primeiro - 1;
  int j;
  for (j = primeiro; j < ultimo; j++) {
    if (vetor[j] <= pivot) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }
  troca(&vetor[i + 1], &vetor[ultimo]);
  return (i + 1);
}

// função principal para o quick sort
void quickSort(int *arr, int primeiro, int ultimo){
  if (primeiro < ultimo) {
    // fazendo a partição
    int parte = particao(arr, primeiro, ultimo);
    // separadamente ordenar cada parte da partição
    quickSort(arr, primeiro, parte - 1);
    quickSort(arr, parte + 1, ultimo);
  }
}

void imprimir(int *vetor, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(void) {
  int n;
  scanf("%d", &n);
  int *vetor = malloc (n * sizeof (int));
  for (int i = 0; i < n; i++){
    scanf("%d", &vetor[i]);
    //printf("vetor[%d]: %d\n", i, vetor[i]);
  }
  //imprimir(vetor, n);
  quickSort(vetor, 0, n - 1);
  imprimir(vetor, n);
  free(vetor);
}
