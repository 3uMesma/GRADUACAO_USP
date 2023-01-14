#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// objetivo: auxilar para o quick sort
void troca(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

// ordenar usando o quick sort mediana de 3:
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

// objetivo: encontrar a soma desejado através de um vetor ordenado
bool busca_ordenada(int *v, int procurado, int tam_vetor){
  int esq = 0, dir = tam_vetor - 1;
  while(esq < dir) {
		if(v[esq] + v[dir] == procurado) {
			return true;
		}
		else if(v[esq] + v[dir] > procurado) {
			dir--;
		}
		else {
			esq++;
		}
	}
  return false;
}

// objetivo: formatar o output
void imprimir_resultado(int *v, int procurado, int tam_vetor){
  if (busca_ordenada(v, procurado, tam_vetor)){
    printf("S\n");
  }
  else{
    printf("N\n");
  }
}

int main(void) {
  int tam_vetor;
  scanf("%d", &tam_vetor);
  int v[tam_vetor];

  // lendo o vetor:
  for (int i = 0; i < tam_vetor; i++){
    scanf("%d", &v[i]);
  }

  // ordenando o vetor:
  quickSort(v, 0, tam_vetor - 1);

  int n_buscas, procurado;
  scanf("%d", &n_buscas);
  for (int i = 0; i < n_buscas; i++){
    scanf("%d", &procurado);
    imprimir_resultado(v, procurado, tam_vetor);
  }
  return 0;
}
