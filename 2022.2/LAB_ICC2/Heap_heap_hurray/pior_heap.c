# include <stdio.h>

void trocar(int *a, int*b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

// a razi é sempre a menor
void heap(int *vetor, int i){
  int pai = (i-1)/2;
  if (vetor[pai] < vetor[i]){
    trocar(&vetor[pai], &vetor[i]);
    heap(vetor, pai);
  }
}

// função principal do heap sort
void heapSort(int *vetor, int tam){
  for (int i = 1; i < tam-1; i++){
    heap(vetor, i);
  }
  // como alguns elementos já foram verificados:
  for (int i = tam - 1; i >= 0; i--){
      // troca a raiz com o ultimo
      trocar(&vetor[0], &vetor[i]);
      for (int j = 1; j < i - 1; j++){
        heap(vetor, j);
      }
   }
}

// imprimir vetor:
void imprimir(int *vetor, int tam){
  for (int i = 0; i < tam; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(){
  // lendo o vetor:
  int tam;
  scanf("%d", &tam);
  int vetor[tam];
  for (int i = 0; i < tam; i++){
    scanf("%d", &vetor[i]);
  }
  // ordenando:
  heapSort(vetor, tam);
  imprimir(vetor, tam);
}
