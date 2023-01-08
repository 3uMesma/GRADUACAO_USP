#include <stdio.h>
#include <stdlib.h>

float **alocar_matriz(int tamanho){
  float **matriz;
  matriz = (float **) calloc(tamanho, sizeof(float *));
  if (matriz == NULL){
    printf("Erro de alocacao de mattriz\n");
    return NULL;
  }

  for (int i = 0; i < tamanho; i++){
    matriz[i] = (float *) calloc(tamanho, sizeof(float));
    if (matriz[i] == NULL){
      for (int k = 0; k < tamanho; k++){
        free(matriz[k]);
      }
      free(matriz);
      return NULL;
    }
  }
  return matriz;
}

void desalocar_matriz(float **matriz, int tamanho){
  for (int i = 0; i < tamanho; i++){
    free(matriz[i]);
  }
  free(matriz);
}

int main(void) {
  int tamanho;
  float **matriz_tipos;

  scanf("%d", &tamanho);
  
  int ataques[tamanho][2];

  matriz_tipos = alocar_matriz(tamanho);

  // lendo os dados da matriz inimigos
  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      scanf("%f", &matriz_tipos[i][j]);
    }
  }

  // lendo os dados da matriz ataques
  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < 2; j++){
      int aux;
      scanf("%d", &aux);
      if (aux == -1){
        break;
      }
      else{
        ataques[i][j] = aux;
      }
    }
  }

  // se livarndo -1
  int lixo;
  scanf("%d", &lixo);
  
  int tipo_inimigo;
  scanf("%d", &tipo_inimigo);

  // pegando o maior valor
  float maior = matriz_tipos[0][tipo_inimigo];
  int indice_maior = 0;
  for (int i = 1; i < tamanho; i++){
    if (matriz_tipos[i][tipo_inimigo] > maior){
      maior = matriz_tipos[i][tipo_inimigo];
      indice_maior = i;
    }
  }

  // valor pelo qual sera multiplicado o ataque
  float dano;
  dano = ataques[indice_maior][0] * maior;

  printf("O melhor ataque possui indice %d e dano %.2f\n", indice_maior, dano);
  desalocar_matriz(matriz_tipos, tamanho);
  return 0;
}
