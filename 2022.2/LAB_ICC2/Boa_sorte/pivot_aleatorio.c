#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

void imprimir(int *vetor, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");
}
  
int particao(int *arr, int primeiro, int ultimo){
  // o primeiro elemento é o pivot
  int pivot = arr[primeiro];
  int i = primeiro - 1, j = ultimo + 1;

  while (1) {
    // vai percorrer o vetor na ordem [0...n] e parar no ultimo elemento menor que o pivot
    do {
      i++;
    } while (arr[i] < pivot);
    // vai percorrer o vetor na ordem [n...0] e parar no ultimo elemento maior que o pivot
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j)return j;
    // vai trocar o menor com o maior 
    troca(&arr[i], &arr[j]);
  }
}
  
int particao_aleatoria(int *arr, int primeiro, int ultimo){
  srand(time(0));
  // pegando um numero elatorio usando srand pra não ser sempre o mesmo número
  int aleatorio = primeiro + rand() % (ultimo - primeiro);
  // estabelecer o pivot aleatorio colocando ele em primeiro lugar
  troca(&arr[aleatorio], &arr[primeiro]); 
  return particao(arr, primeiro, ultimo);
}
  
void quickSort(int *arr, int primeiro, int ultimo){
  if (primeiro < ultimo) {
    int parte = particao_aleatoria(arr, primeiro, ultimo);
    quickSort(arr, primeiro, parte);
    quickSort(arr, parte + 1, ultimo);
  }
}
  
int main(){
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
