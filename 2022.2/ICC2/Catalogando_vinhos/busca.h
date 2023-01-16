#ifndef BUSCA_H
#define BUSCA_H
  #include <stdio.h>
  #include <stdlib.h>
# include <string.h>

  typedef struct vinho{
  int ID;
  double acido_citrico;
  double acucar_residual;
  double densidade;
  double PH;
  double alcool;
  double aux;
  }VINHO;


  VINHO *cadastrar_vinhos(int *qtd_vinhos);
  void imprimir_vinhos(VINHO *vinhos, int qtd_vinhos);
  void escolher_ordenacao(VINHO *vinhos, int qtd_vinhos);
  void mergeSort(VINHO *vinhos, int esq, int dir);
  void qtd_encontrado(VINHO *vinhos, int esq, int dir);

#endif