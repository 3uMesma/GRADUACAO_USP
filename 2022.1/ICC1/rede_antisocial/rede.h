#ifndef REDE_H
#define REDE_H
  # include <stdio.h>
  # include <stdlib.h>
  # include <string.h>

  #define TAM_MAX 100

  char **alocar_nomes(int qtt_nomes);
  int **alocar_inimizades(int qtt_nomes);
  void imprimir_mesmo_nome(char **matriz_nomes, char **matriz_sobrenomes, int qtt_nomes, int **matriz_inimizades);
  void troca_inimizades(int qtt_nomes, int **matriz_inimizades);
  void possiveis_amigos(char **matriz_nomes, char **matriz_sobrenomes, int qtt_nomes, int **matriz_inimizades);
  void ordenar_sobrenome(char **matriz_nomes, char **matriz_sobrenomes, int qtt_nomes);
  void desalocar_memoria_char(char **matriz, int qtt_nomes);
  void desalocar_memoria_int(int**matriz, int qtt_nomes);

#endif