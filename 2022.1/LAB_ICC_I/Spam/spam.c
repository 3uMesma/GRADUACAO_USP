#include <stdio.h>
#include <string.h>

int main () {
  char spam[12][20] = {"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda", "SOS"};
  char texto[2000];
  char *presente;
  char c;
  int i = 0, caracteres[100], letras = 0, k = 0, proibidas = 0;

  //recolhendo os dados do texto
  do {
    c = getchar();
    texto[i] = c;
    i++;
    letras++;
    if (c == '\n'){
      caracteres[k] = letras;
      letras = 0;
      k++;
    }
  }
    while(c != EOF);

  // repetindo o processo para cada palavra proibida
  for (int j = 0; j < 12; j++){
    presente = strstr(texto, spam[j]);

    // se a palavra está no texto...
    if (presente != NULL){
      proibidas++;
    }
    if (proibidas >= 2){
      printf("Spam\n");
      return 0;
    }
  }

  // vendo se alguma frase tem mais de 76 caracteres
  for (int j = 0; j < k; j++){
    if (caracteres[j] > 76){
      printf("Spam\n");
      return 0;
    }
  }

  printf("Inbox\n");

   return(0);
}
