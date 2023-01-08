#include <stdio.h>

double conta_palavras(FILE *arq){
  double palavras = 0.0;
  char c = '\0', ant, letra = 0;

  do{
    ant = c;
    c = fgetc(arq);
    if (c != '\r' && c != '\t' && c != '\n' && c != ' '){
      letra = 1; // quando encontrar letra, ela marca um
    }
    else{
      if (letra == 1){
        palavras++;
      }
      letra = 0;
    }
  }
  while(feof(arq) == 0);

  // vendo se o texto não terminou em um caractere
  if (ant != '\r' && ant != '\t' && ant != '\n' && ant != ' '){
    palavras++;
  }
  
  return palavras;
}

int main(void) {
  char nome_arquivo_original[200], nome_arquivo_usuario[200];
  FILE *arq_original, *arq_usuario;
  double palavras_original, palavras_usuario;

  scanf("%s", nome_arquivo_original);
  scanf("%s", nome_arquivo_usuario);

  arq_original = fopen(nome_arquivo_original, "r");
  palavras_original = conta_palavras(arq_original);
  arq_usuario = fopen(nome_arquivo_usuario, "r");
  palavras_usuario = conta_palavras(arq_usuario);

  printf("O candidato digitou %d de %d palavras (%d%%).\n", (int)palavras_usuario, (int)palavras_original, ((int)((palavras_usuario/palavras_original) * 100)));

  if (((int)((palavras_usuario/palavras_original) * 100)) >= 20){
    printf("Parabéns, candidato! Você foi aprovado!\n");
  }
  else{
    printf("Lamentamos informar, mas você não cumpre os requisitos da vaga, candidato!\n");
  }

  fclose(arq_original);
  fclose(arq_usuario);
  return 0;
}
