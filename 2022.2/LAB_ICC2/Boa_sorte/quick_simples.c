#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}
  
int particao(int *arr, int primeiro, int ultimo){
  // o pivô é o último elemento
  int pivot = arr[ultimo]; 
  // index do menor elemento
  int i = (primeiro - 1); 
  
  for (int j = primeiro; j < ultimo; j++) {
  // se o elemento atual for menor que o pivot:
    if (arr[j] < pivot) {
      // incrementa o index do que achavamos que era o menor elemento e trocamos ele com o realmente menor
      i++;
      troca(&arr[i], &arr[j]);
    }
  }
  // depois troca o pivo com o menor:
  troca(&arr[i + 1], &arr[ultimo]);
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
  for (int i = 0; i <= n; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(){
  int n;
  scanf("%d", &n);
  int *vetor = malloc ((n + 1) * sizeof (int));
  for (int i = 0; i <= n; i++){
    scanf("%d", &vetor[i]);
  }
  imprimir(vetor, n);
  quickSort(vetor, 0, n);
  imprimir(vetor, n);
}
