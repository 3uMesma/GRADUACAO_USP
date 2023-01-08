#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **alocar_matriz(int linha, int coluna){
  char **matriz;
  matriz = (char **) calloc(linha, sizeof(char *));
  if (matriz == NULL){
    printf("Erro de alocacao de matriz\n");
    return NULL;
  }

  for (int i = 0; i < linha; i++){
    matriz[i] = (char *) calloc(coluna, sizeof(char));
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

void desalocar_matriz(char **matriz, int linha){
  for (int i = 0; i < linha; i++){
    free(matriz[i]);
  }
  free(matriz);
}

char *readLine(){
  char *linha = NULL;
  int i = 0;
  char c;

  do {
    c = getchar();
    linha = (char*)realloc(linha, (++i) * sizeof(char));
    linha[i - 1] = c;
  }
    while(c != '\n' && c != '\r');

    linha[i - 1] = '\0';

   return linha;
}

void troca_sobrenome(char **nomes, int qtt_nomes){

  for (int i = 0; i < qtt_nomes - 1; i++){
    int k = 0, posicao_sobrenome;
    if (i % 2 == 0){
      int final = strlen(nomes[i]) - 1;
      // identificando a posicao do ultimo sobrenome
      for (int j = final; j > 0; j--){
        if (nomes[i][j] == ' '){
          posicao_sobrenome = j;
          break;
          }
        }
        //pegando o ultimo sobrenome
        char *sobrenome;
        sobrenome = (char *) calloc(final + 2 - posicao_sobrenome, sizeof(char));
        for (int l = posicao_sobrenome; l <= final; l++){
          sobrenome[k] = nomes[i][l];
          k++;
        }
        // incrementando no proximo nome e alocando mais espaço
        if (i != qtt_nomes){
          int tamanho_proxima = strlen(nomes[i + 1]);
          nomes[i + 1] = (char *) realloc (nomes[i + 1], sizeof (char) * (tamanho_proxima + final + 2 - posicao_sobrenome));
          strcat(nomes[i+1], sobrenome);
        }
        free(sobrenome);
      }
  }
}

int main(void) {
  char **nomes = NULL;
  int qtt_nomes = 0, tam = 0;

  nomes = alocar_matriz(1, 1);

  do{
    qtt_nomes++;
    nomes = (char **) realloc (nomes, sizeof (char *) * (qtt_nomes));
    nomes[qtt_nomes - 1] = readLine();
    tam = strlen(nomes[qtt_nomes - 1]);
  }
    while(nomes[qtt_nomes - 1][tam - 1] != '$');

      nomes[qtt_nomes - 1][tam - 1] = '\0';

  troca_sobrenome(nomes, qtt_nomes);

  for (int i = 0; i < qtt_nomes; i++){
    printf("%s\n", nomes[i]);
    }

    desalocar_matriz(nomes, qtt_nomes);

  return 0;
}
