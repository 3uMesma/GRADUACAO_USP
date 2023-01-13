#include <stdio.h>

// objetivo: trocar elementos
void trocar(int* a, int* b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

// objetivo: fazer com que a raiz seja a maior
void heapify(int arr[], int tam, int i){
  // inicializando a raiz:
  int raiz = i;
  // seu filho da esquerda é:
  int esq = (2 * i) + 1;
  // e seu filho da direita é:
  int dir = (2 * i) + 2;
 
  // se o filho da esquerda é maior que seu pai:
  if (esq < tam && arr[esq] > arr[raiz]){
    raiz = esq;
  }
  // se o filho da direita é maior que seu pai:
  if (dir < tam && arr[dir] > arr[raiz]){
    raiz = dir;
  }
  // se a raiz não for a maior, continuar o processo
  if (raiz != i) {
    trocar(&arr[i], &arr[raiz]);
    // chamando recursivamente a sub-arvore:
    heapify(arr, tam, raiz);
  }
}

// objetivo: função principal do heap sort:
void heapSort(int arr[], int tam){
  // deixando a árvore em maxheap:
  for (int i = tam / 2 - 1; i >= 0; i--){
    heapify(arr, tam, i);
  }
  // fazendo isso recursivamente para sempre pegar o maior:
  for (int i  = tam - 1; i >= 0 ; i--){
    trocar(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

// objetivo: imprimir vetor
void imprimir(int arr[], int tam){
  for (int i = 0; i < tam; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  // lendo o vetor:
  int tam;
  scanf("%d", &tam);
  int arr[tam];
  for (int i = 0; i < tam; i++){
    scanf("%d", &arr[i]);
  }
  // ordenando:
  heapSort(arr, tam);
  imprimir(arr, tam);
}
