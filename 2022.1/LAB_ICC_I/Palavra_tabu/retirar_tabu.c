#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readLine(){
  char *linha = NULL;
  int i = 0;
  char c;

  do {
    c = getchar();
    if (c == 10)break; // 10 = quebra_linha
      linha = realloc(linha, (++i) * sizeof(char));
      linha[i - 1] = c;
  }
    while(c != '\n' && c != '$');

  if (i == 0) {
      free (linha);
      return NULL;
    }
   return linha;
  free(linha);
}

int aparencias(char *palavra_tabu, char *texto, int inicio){
  int i, j = 0;
  for (i = inicio; i < strlen(texto); i++){
    if (texto[i] == palavra_tabu[j]){
      j++;
    }
    else{
      j = 0;
    }
    if (j == strlen(palavra_tabu)){
      return i;
    }
  }
  return -1;
}

void apaga_palavra(char *palavra_tabu, char *texto, int inicio){
  int comeco_mudanca = inicio - (strlen(palavra_tabu) - 1);
  for (int k = comeco_mudanca; k < strlen(texto); k++){
    texto[k] = texto[k + strlen(palavra_tabu)];
  }
  for (int i = strlen(palavra_tabu); i > 0; i--){
    texto[strlen(texto) + i - 1] = 0;
  }
}

int main(void) {
  char *palavra_tabu;
  char *texto, *auxiliar;
  int tam, tam_total = 0;

  palavra_tabu = readLine();

  // Primeiro, irei criar o vetor texto com um valor maximo e depois ajusto para o tamanho real do texto com realloc
  texto = (char *) calloc(1, sizeof(char));

    auxiliar = readLine();
    tam = strlen(auxiliar);
    tam_total += tam;
    texto = realloc(texto, tam_total * sizeof(char));
    if (texto[0] == 0){
      strcpy(texto, auxiliar);
    }
    else{
      for (int i = 0; i < tam; i++){
        strcat(texto, auxiliar);
      }
    }  

  //verificando se tem igual
  int inicio = 0, vezes = 0;

  do {
    inicio = aparencias(palavra_tabu, texto, inicio);
    if (inicio != -1){
      apaga_palavra(palavra_tabu, texto, inicio);
      vezes++;
      inicio = 0;
    }
    else {
      break;
    }
  }
    while(inicio != -1);

  printf("A palavra tabu foi encontrada %d vezes\n", vezes);
  for (int i = 0; i < strlen(texto); i++){
    if (texto[i] == '$'){
      texto[i] = 0;
    }
  }
  printf("Frase: %s\n", texto);
  free(texto);
  free(palavra_tabu);
  free(auxiliar);
  return 0;
}
