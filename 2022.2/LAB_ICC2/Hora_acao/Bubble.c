#include <stdio.h>
#include <stdlib.h>

int *aloca(int qtd_entrada){
  int *vetor_gomas;
  vetor_gomas = (int*) malloc(qtd_entrda * sizeof(int));
  if (vetor_gomas == NULL){
    printf("Erro de alocacao\n");
    free(vetor_gomas);
  }
  for (int i = 0; i < qtd_entrada; i++){
    scanf("%d", &vetor_gomas[i]);
  }
  return vetor_gomas;
}

void calcula_ganhador(int qtd_entrada, int *vetor_gomas){
  int qtd_trocas = 0, aux;
  for (int i = 0; i < qtd_entrada; i++){
    for (int j = 0; j < qtd_entrada; j++){
      if(vetor_gomas[j] > vetor_gomas[j + 1]{
        aux = vetor_gomas[j];
        vetor_gomas[j] = vetor_gomas[j + 1];
        vetor_gomas[j + 1] = aux;
        qtd_trocas++;
      }
    }
  }
  // caso as trocas sejam par, Fino ganha:
  if (qtd_trocas % 2 == 0){
    printf("Fino\n");
  }
  else{
    printf("Jaques\n");
  }
}
         
int main(){
  int qtd_entrada, *vetor_gomas;
  do{
    scanf("%d", &qtd_entrada);
    if(qtd_entrada != 0){
      vetor_gomas = aloca(qtd_entrada);
      calcula_ganhador(qtd_entrada, vetor_gomas);
      free(vetor_gomas);
    }
  }while(qtd_entrada != 0);
  return 0;
}
