#include <stdio.h>

int main(void) {
  // lendo os rotores
  
  int rotores[3][26];
  int vezes0 = 0, vezes1 = 0;
  
  scanf("Rotores:\n");
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 26; j++){
      scanf("%d ", &rotores[i][j]);
    }
  }

  // lendo o enigma
  
  char c,  enigma[1000000];
  int i = 0, novo_c;
  
  scanf("Mensagem:\n");
  do{
    c = getchar();
    enigma[i] = c;
    i++;
  }
    while(c != EOF);

  // decifrando...
  for (int j = 0; j < i - 1; j++){
    int posicao = 0;
    if (enigma[j] >= 65 && enigma[j] <= 90) {
      // caso seja maiscula
      posicao = enigma[j] - 'A';
      novo_c = rotores[0][posicao];
      novo_c = rotores[1][novo_c];
      novo_c = rotores[2][novo_c];
      printf("%c", novo_c + 'A');
    } 
    else if (enigma[j] >= 97 && enigma[j] <= 122){
      // caso seja minuscula
      posicao = enigma[j] - 'a';
      novo_c = rotores[0][posicao];
      novo_c = rotores[1][novo_c];
      novo_c = rotores[2][novo_c];
      printf("%c", novo_c + 'a');
    }
    else{
      // carecteres especiais não precisam ser desincriptografados 
      printf("%c", enigma[j]);
    }

    
    // rotacionando
    if ((enigma[j] >= 65 && enigma[j] <= 90)|| (enigma[j] >= 97 && enigma[j] <= 122)){
      int aux = rotores[0][0];
      for (int k = 0; k <= 24; k++){
        rotores[0][k] = rotores[0][k+1];
      }
      rotores[0][25] = aux;
      vezes0++;
      if (vezes0 == 26){
        vezes0 = 0;
        // segundo rotor roda
        aux = rotores[1][0];
        for (int j = 0; j <= 24; j++){
          rotores[1][j] = rotores[1][j+1];
      }
      rotores[1][25] = aux;
        vezes1++;
      if (vezes1 == 26){
        vezes1 = 0;
        // terceiro rotor roda
        aux = rotores[2][0];
        for (int l = 0; l <= 24; l++){
          rotores[2][l] = rotores[2][l+1];
      }
        rotores[2][25] = aux;
    }
  }
}
    }
  return 0;
  }
