#include <stdio.h>

int main(void) {
  int vetor[25]; 
  int aparicoes[5] = {0, 0, 0, 0, 0};
  
  //lê o array//
  for (int i = 0; i < 25; i++){
    scanf("%d", &vetor[i]);
    // lista as aparições por cores //
    for (int j = 0; j < 5; j++){
      if (vetor[i] == j){
        aparicoes[j]++;
      }
    }
  }

  // printa o histograma
  int maior = - 1, moda;
  for (int k = 0; k < 5; k++){
    printf("%d: |", k);
    // vê qual cor aparece mais
    if (aparicoes[k] > maior){
      maior = aparicoes[k];
      moda = k;
    }
    while (aparicoes[k] > 0){
      printf("#");
      aparicoes[k]--;
    }
  printf("\n");
  }

  // ve as posições do que aparece mais e printa
  for (int l = 0; l < 25; l++){
    if (vetor[l] == moda){
      printf("%d\n", l);
    }
  }
  
  
  return 0;
}
