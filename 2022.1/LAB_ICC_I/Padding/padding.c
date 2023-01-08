#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int linha, int coluna){
  int **matriz;
  matriz = (int **) calloc(linha, sizeof(int *));
  if (matriz == NULL){
    printf("Erro de alocacao de matriz\n");
    return NULL;
  }

  for (int i = 0; i < linha; i++){
    matriz[i] = (int *) calloc(coluna, sizeof(int));
    if (matriz[i] == NULL){
      for (int k = 0; k < coluna; k++){
        free(matriz[k]);
      }
      free(matriz);
      return NULL;
    }
  }
  return matriz;
}

void desalocar_matriz(int **matriz, int linha){
  for (int i = 0; i < linha; i++){
    free(matriz[i]);
  }
  free(matriz);
}

void criando_borda(int **imagem, int altura, int largura, int borda){
  int **imagem_borda;
  int altura_nova = altura + (borda * 2);
  int largura_nova = largura + (borda * 2);

  imagem_borda = alocar_matriz(altura_nova, largura_nova);

  for (int i = 0; i < altura + (borda * 2); i++){
    for (int j = 0; j < largura + (borda * 2); j++){
      imagem_borda[i][j] = 0;
    }
  }

  for (int i = 0; i < altura; i++){
    for (int j = 0; j < largura; j++){
      imagem_borda[i + borda][j + borda] = imagem[i][j];
    }
  }

  for (int i = 0; i < altura + (borda * 2); i++){
    for (int j = 0; j < largura + (borda * 2); j++){
      printf("%d ", imagem_borda[i][j]);
    }
    printf("\n");
  }
  
  }

int main(void) {
  int largura, altura, borda;
  int **imagem;
  
  scanf("%d %d", &largura, &altura);
  imagem = alocar_matriz(altura, largura);

  for (int i = 0 ; i < altura; i++){
    for (int j = 0; j < largura; j++){
      scanf("%d", &imagem[i][j]);
    }
  }

  scanf("%d", &borda);

  criando_borda(imagem, altura, largura, borda);

  printf("\n");

  for (int i = 0; i < altura; i++){
    for (int j = 0; j < largura; j++){
      printf("%d ", imagem[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
