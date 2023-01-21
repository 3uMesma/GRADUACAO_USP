#ifndef CADASTRO_ALUNOS_H
#define CADASTRO_ALUNOS_H
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>

  typedef struct aluno{
  char *nome;
  double media;
  int *notas;
  }ALUNO;

  ALUNO *cadastrar_alunos(int qtd_alunos, int qtd_notas);
  void imprimir_alunos(ALUNO *alunos, int qtd_alunos, int qtd_notas);
  void heapSort(ALUNO *alunos, int qtd_alunos, int qtd_notas);

#endif