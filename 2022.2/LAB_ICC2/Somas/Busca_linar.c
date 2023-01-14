#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// objetivo: determinar se o numero pode ser formando no vetor
bool busca_sequencial(int *v, int procurado, int tam_vetor){
  // fazendo a busca sequencial:
  for (int i = 0; i < tam_vetor; i++){
    for (int j = i + 1; j < tam_vetor; j++){
      // verificando se esses dois elementos resultam no que procuramos:
      if (v[i] + v[j] == procurado){
        return true;
      }
    }
  }
  return false;
}

// objetivo: formatar o output
void imprimir_resultado(int *v, int procurado, int tam_vetor){
  if (busca_sequencial(v, procurado, tam_vetor)){
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

  int n_buscas, procurado;
  scanf("%d", &n_buscas);
  for (int i = 0; i < n_buscas; i++){
    scanf("%d", &procurado);
    imprimir_resultado(v, procurado, tam_vetor);
  }
  return 0;
}
