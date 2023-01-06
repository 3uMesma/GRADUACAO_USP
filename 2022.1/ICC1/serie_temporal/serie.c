#include <stdio.h>
#include <math.h>

int main(void) {
  int tam, sub;
  printf("Digite a quantidade de sequencias: ");
  scanf("%d", &tam);
  printf("Digite o tamanho da sub-sequência: ");
  scanf("%d", &sub);

  int vetor[tam][sub];
  for (int j = 0; j < tam; j++){
    for (int i = 0; i < sub; i++){
    printf("Digite um elemento da subsequecia %d: ", j);
    scanf("%d", &vetor[j][i]);
  }
    printf("\n");
  }

  int soma_n = 0, soma_d1 = 0, soma_d2 = 0;
  int dif[tam], maior[3];
  int k = 0;
  
  // fazendo bi^2
  for (int i = 0; i < sub; i++){
    soma_d2 += vetor[tam][i];
  }
  
  for (int i = 0; i < tam; i++){
    for (int j = 0; j < sub; j++){
      // fazendo a soma do numerador
      soma_n += vetor[i][j] * vetor[tam][j];
    }

    // fazendo ai^2
    for (int j = 0; j < sub; j++){
      soma_d1 += pow(vetor[i][j], 2);
    }

    dif[i] = soma_n / (sqrt(soma_d1) * sqrt(soma_d2));
  }

  // pegando os tres maiores elementos da lista
  for (int i = 0; i < tam; i++){
    if(dif[i] > dif[i + 1]){
      maior[k] = i;
      k++;
    }
  }

  printf("Os três mais próximos são:\n");
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < sub; j++){
      printf("%d ", vetor[maior[i]][j]);
    }
    printf("\n");
  }
  return 0;
}
