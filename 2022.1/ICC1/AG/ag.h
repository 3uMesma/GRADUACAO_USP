#ifndef AG_H
#define AG_H
  #include <stdio.h>
  #include <time.h>
  #include <stdlib.h>
  #include <stdbool.h>

  typedef struct candidato CANDIDATO;

  struct candidato{
    int numero;
    int fitness;
  };

  int *ler_const();
  void aleatorios(int tam, CANDIDATO *geracao);
  void calcular_fitness(int tam, CANDIDATO *geracao, int *constantes);
  void melhores(CANDIDATO *geracao, int tam, double mutacao);
  bool candidato_ideal(CANDIDATO *geracao, int tam);
  void imprimir_vetor(CANDIDATO *geracao, int tam);

#endif