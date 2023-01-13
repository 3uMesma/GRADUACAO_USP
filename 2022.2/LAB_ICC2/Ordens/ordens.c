#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// criando uma struct pra facilitar a ordenação e organização
typedef struct {
  int ID;
  char cor[10];
  double comprimento;
  double nota;
} brinquedo;

void imprimir(brinquedo *brinquedos_t, int n){
  for (int i = 0; i <n; i++){
    printf("%d;", brinquedos_t[i].ID);
  }
  printf("\n");
}

void imprimir_struct(brinquedo *brinquedos_t, int i){
  printf("ID: %d\n", brinquedos_t[i].ID);
  printf("cor: %s\n", brinquedos_t[i].cor);
  printf("comprimento: %.2lf\n", brinquedos_t[i].comprimento);
  printf("nota: %.2lf\n", brinquedos_t[i].nota);
  printf("\n");
}

// criando uma função para cada método de ordenação
// mas antes fazendo uma função genérica para trocar elementos da struct
void trocar(brinquedo *brinquedos_t, int i, int j){
  brinquedo aux = brinquedos_t[i];
  brinquedos_t[i] = brinquedos_t[j];
  brinquedos_t[j] = aux;
}
 
// Agora fazendo o Bubble Sort:
void bubbleSort(brinquedo *brinquedos_t, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++){
    for (j = 0; j < n - i - 1; j++){
      // usei strcmp para ordenar em ordem alfabética pois ele retorna menor que 0 quando encontra um carácter diferente nas strings e esse carácter da primeira é menor que o da segunda e retorna maior que zero para a situação oposta
      // se for maior então pode trocar direto...
      if (strcmp(brinquedos_t[j].cor, brinquedos_t[j + 1].cor) > 0){
        trocar(brinquedos_t, j, j + 1);
      }
      // mas se for igual temos que comparar pelo tamanho:
      else if(strcmp(brinquedos_t[j].cor, brinquedos_t[j + 1].cor) == 0){
        // verificando qual é maior
        if (brinquedos_t[j].comprimento > brinquedos_t[j + 1].comprimento){
          trocar(brinquedos_t, j, j + 1);
        }
        // mas caso o tamanho seja igual tbm, o ultimo criterio de desempate será a nota:
        else if(brinquedos_t[j].comprimento == brinquedos_t[j + 1].comprimento){
          if (brinquedos_t[j].nota < brinquedos_t[j + 1].nota){
            trocar(brinquedos_t, j, j + 1);
          }
        }
      }
    }
  }
}

// Agora fazendo o Insertion Sort:
void insertionSort(brinquedo *brinquedos_t, int n)
{
  int i, j;
  imprimir(brinquedos_t, n);
  // começando a organizar pela cor:
  for (i = 1; i < n; i++) {
    j = i - 1;
    // se for maior então pode trocar direto
    while (j >= 0 && strcmp(brinquedos_t[j].cor, brinquedos_t[j + 1].cor) > 0) {
      trocar(brinquedos_t, j + 1, j);
      j--;
    }
    // se for igual então comparamos o tamanho
    if (j >= 0 && strcmp(brinquedos_t[j].cor, brinquedos_t[j + 1].cor) == 0){
      while (j >= 0 && brinquedos_t[j].comprimento > brinquedos_t[j + 1].comprimento){
        trocar(brinquedos_t, j + 1, j);
        j--;
      }
      // mas caso o tamanho tbm seja igual, temos que comparar pela nota:
      if (j >= 0 && (brinquedos_t[j].comprimento == brinquedos_t[j + 1].comprimento)){
        if (j >= 0 && brinquedos_t[j].nota < brinquedos_t[j + 1].nota){
          trocar(brinquedos_t, j + 1, j);
          j--;
        }
      }
    }
  }
}

// Fazendo a lógica do Merge
void merge(brinquedo *brinquedos_t, int esquerda, int meio, int direita)
{ 
  int i, j, k;
  // encontrando o numero de elementos, para realizar a divisão
  int parte_1 = meio - esquerda + 1;
  int parte_2 = direita - meio;
 
  // criando structs auxiliares com metade da antiga
  brinquedo brinquedos_esq[parte_1];
  brinquedo brinquedos_dir[parte_2];

  // copiando a informação para esses vetores 
  for (i = 0; i < parte_1; i++){
    brinquedos_esq[i] = brinquedos_t[esquerda + i];
  }
  //imprimir(brinquedos_esq, meio);
  for (j = 0; j < parte_2; j++){
    brinquedos_dir[j] = brinquedos_t[meio + j + 1];
  }
  //imprimir(brinquedos_dir, meio);
 
  i = 0;
  j = 0;
  k = esquerda;

  // ordenando as partes 
  while (i < parte_1 && j < parte_2) {
    // ordenando baseado no nome
    if (strcmp(brinquedos_esq[i].cor, brinquedos_dir[j].cor) < 0) {
      brinquedos_t[k] = brinquedos_esq[i];
      i++;
    }
    // se os nomes forem iguais
    else if (strcmp(brinquedos_esq[i].cor, brinquedos_dir[j].cor) == 0){
      // agora testar o comprimento
      if (brinquedos_esq[i].comprimento < brinquedos_dir[j].comprimento){
      brinquedos_t[k] = brinquedos_esq[i];
      i++;
      }
        // se os comprimentos também forem iguais, testar com as notas
      else if(brinquedos_esq[i].comprimento == brinquedos_dir[j].comprimento){
        if (brinquedos_esq[i].nota >= brinquedos_dir[j].nota){
          brinquedos_t[k] = brinquedos_esq[i];
          i++;
        }
        else{
          brinquedos_t[k] = brinquedos_dir[j];
          j++;
        }
      }
      else{
        brinquedos_t[k] = brinquedos_dir[j];
        j++;
      }
    }
    // caso as condições não sejam satsifeitas, pegar o da direita
    else {
      brinquedos_t[k] = brinquedos_dir[j];
      j++;
    }
    k++;
    //printf("Vetor na momento[%d]:\n", k);
    //imprimir(brinquedos_t, direita);
  }
 
  // se os elementos da direita já foram todos ordenados, copiar o restante do vetor da esquerda
  while (i < parte_1) {
      brinquedos_t[k] = brinquedos_esq[i];
      i++;
      k++;
    }
 
  // fazendo o mesmo processo caso ocorra com a direita
  while (j < parte_2) {
      brinquedos_t[k] = brinquedos_dir[j];
      j++;
      k++;
    }
}

// Fazendo o Merge Sort em si:
void mergeSort(brinquedo *brinquedos_t, int esquerda, int direita){
  if (esquerda < direita) {
    // Isso é o mesmo que (esquerda + direita)/2, só que dessa forma evita overflow
    int meio = esquerda + (direita - esquerda) / 2;
    // trabalhando com cada metade
    mergeSort(brinquedos_t, esquerda, meio);
    mergeSort(brinquedos_t, meio + 1, direita);
    merge(brinquedos_t, esquerda, meio, direita);
    }
}

// Fazendo o Quick Sort:
int particao_quick(brinquedo *brinquedos_t, int primeiro, int ultimo){
  int pivot = ultimo;
  int i = primeiro - 1;
  for (int j = primeiro; j <= ultimo - 1; j++){
    if (strcmp(brinquedos_t[j].cor, brinquedos_t[pivot].cor) < 0){
      i++;
      trocar(brinquedos_t, i, j);
    }
    else if (strcmp(brinquedos_t[j].cor, brinquedos_t[pivot].cor) == 0){
      if (brinquedos_t[j].comprimento < brinquedos_t[pivot].comprimento){
        i++;
        trocar(brinquedos_t, i, j);
      }
      else if (brinquedos_t[j].comprimento == brinquedos_t[pivot].comprimento){
        if (brinquedos_t[j].nota > brinquedos_t[pivot].nota){
          i++;
          trocar(brinquedos_t, i, j);
        }
      }
    }
  }
  trocar(brinquedos_t, i + 1, ultimo);
  return (i + 1);
}

void quickSort(brinquedo *brinquedos_t, int primeiro, int ultimo){
  if (primeiro < ultimo) {
    int parte = particao_quick(brinquedos_t, primeiro, ultimo);
    quickSort(brinquedos_t, primeiro, parte - 1);
    quickSort(brinquedos_t, parte + 1, ultimo);
    }
}

int main(void) {
  // leitura da quantidade de brinquedos
  int n;
  scanf("%d", &n);
  // definindo um vetor de struct com o tamanho informado
  brinquedo *brinquedos_t = (brinquedo*) malloc(sizeof(brinquedo) * n);
  // lendo as informações nescessárias
  for (int i = 0; i < n; i++){
    brinquedos_t[i].ID = i;
    scanf("%s", brinquedos_t[i].cor);
    scanf("%lf", &brinquedos_t[i].comprimento);
    scanf("%lf", &brinquedos_t[i].nota);
    printf("Li %d vezes\n", i);
  }
  // chamando o método de ordenação
  //bubbleSort(brinquedos_t, n);        
  //insertionSort(brinquedos_t, n);
  mergeSort(brinquedos_t, 0, n - 1);
  //quickSort(brinquedos_t, 0, n - 1);
  imprimir(brinquedos_t, n);
  free(brinquedos_t);
  return 0;
}
