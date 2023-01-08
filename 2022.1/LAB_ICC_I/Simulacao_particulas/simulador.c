#include <stdio.h>

char matriz[32][64];
const int tam = 2048;

void fisica_particulas(char matriz[32][64], int tam){
  // criando a copia
  char copia [32][64];
  
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 64; j++){
      copia[i][j] = matriz[i][j];
    }
  }

  // verificando que particula eh
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 64; j++){
      // caso seja areia
      if (matriz[i][j] == '#'){
        // testando embaixo
        if (i != 31 && (matriz[i + 1][j] == '~' || matriz[i + 1][j] == ' ')){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i + 1][j];
          copia[i + 1][j] = auxiliar;
        }
        // testando diagonal esquerda
        else if (j != 0 && i != 3 && (matriz[i + 1][j - 1] == '~' || matriz[i + 1][j - 1] == ' ')){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i + 1][j - 1];
          copia[i + 1][j - 1] = auxiliar;
        }
        // testando diagonal direita
        else if (j != 63 && i != 3 && (matriz[i + 1][j + 1] == '~' || matriz[i + 1][j + 1] == ' ')){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i + 1][j + 1];
          copia[i + 1][j + 1] = auxiliar;
        }
      }
      // caso seja agua
      else if (matriz[i][j] == '~'){
        if (i != 31 &&  matriz[i + 1][j] == ' '){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i + 1][j];
          copia[i + 1][j] = auxiliar;
        }
        // testando diagonal esquerda
        else if (j != 0 && i != 31 && matriz[i + 1][j - 1] == ' '){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i + 1][j - 1];
          copia[i + 1][j - 1] = auxiliar;
        }
        // testando diagonal direita
        else if (j != 63 && i != 31 && matriz[i + 1][j + 1] == ' '){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i + 1][j + 1];
          copia[i + 1][j + 1] = auxiliar;
        }
        // testando a esquerda
        else if (j != 0 && matriz[i][j - 1] == ' '){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i][j - 1];
          copia[i][j - 1] = auxiliar;
        }
          // testando a direita
        else if (j != 63 && matriz[i][j + 1] == ' '){
          int auxiliar = copia[i][j];
          copia[i][j] = copia[i][j + 1];
          copia[i][j + 1] = auxiliar;
        }
      }
    }
  }

  // atualizado a matriz original
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 64; j++){
      matriz[i][j] = copia[i][j];
    }
  }
}
int main(void) {

  // colocando todos os elemntos como ar
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 64; j++){
      matriz[i][j] = ' ';
    }
  }
  int n_frames, frame, x, y;
  char nova_particula;
  
  
  scanf("%d", &n_frames);

  int contador = 0;
  while (contador < n_frames) {
    int n_lido = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);
    if (n_lido == EOF) {
      frame = n_frames;
      }

    while (contador < frame) {
      printf("frame: %d\n", contador + 1);
      for (int i = 0; i < 32; i++){
        for (int j = 0; j < 64; j++){
          printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
      fisica_particulas(matriz, tam);
      contador++;
      }

    if (n_lido != EOF) {
      matriz[y][x] = nova_particula;
        }
}
  return 0;
}
