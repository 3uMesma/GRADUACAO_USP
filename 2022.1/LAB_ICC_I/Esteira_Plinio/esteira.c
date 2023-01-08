#include <stdio.h>

int main(void) {
  char esteira[32][32];
  char resto;
  int inicio_i, inicio_j;
  int direcao;
  
  // apenas lendo as informacoes
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 32; j++){
      scanf("%c", &esteira[i][j]);
      scanf("%c", &resto); 
      if (esteira[i][j] == '[') {
        inicio_i = i;
        inicio_j = j + 1;
      }
    }
    resto = getchar();
  }

  // a partir do [, estabelecer o movimento do plinio]
  while (esteira[inicio_i][inicio_j] != ']'){
    if (esteira[inicio_i][inicio_j] == '.'){
      printf("Loop infinito.\n");
      break;
    }
    else if (esteira[inicio_i][inicio_j] == '>'){
      esteira[inicio_i][inicio_j] = '.';
      inicio_j++;
      direcao = 1;
    }
    else if(esteira[inicio_i][inicio_j] == 'v'){
      esteira[inicio_i][inicio_j] = '.';
      inicio_i++;
      direcao = 2;
    }
    else if(esteira[inicio_i][inicio_j] == '<'){
      esteira[inicio_i][inicio_j] = '.';
      inicio_j--;
      direcao = 3;
    }
    else if (esteira[inicio_i][inicio_j] == '^'){
      esteira[inicio_i][inicio_j] = '.';
      inicio_i--;
      direcao = 4;
    }
    else if(esteira[inicio_i][inicio_j] == '#'){
      if (direcao == 1)inicio_j++;
      if (direcao == 2)inicio_i++;;
      if (direcao == 3)inicio_j--;
      if (direcao == 4)inicio_i--;
      }
    else {
    printf("Falha na esteira.\n");
    break;
  }
    }
  if (esteira[inicio_i][inicio_j] == ']'){
    printf("Ok.\n");
  }

  // imprimindo com os pontos
  for (int i = 0; i < 32; i++){
    for( int j = 0; j < 32; j++){
      printf("%c ", esteira[i][j]);
    }
    printf("\n");
  }
  return 0;
}