#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H
  #include <stdio.h>
  #include <stdlib.h>

  void menu();
  void novo_brilho(float **matriz, int altura, int largura, float brilho);
  void inverter(float **matriz, int altura, int largura, int direcao);
  float **rotacionar(float **matriz, int altura, int largura, int sentido);
  float **redimensionar(float **matriz, int altura, int largura, float escala);
  void imprimir_matriz(float **matriz, int altura, int largura);

#endif