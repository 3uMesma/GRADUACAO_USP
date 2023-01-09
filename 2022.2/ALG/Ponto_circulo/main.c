#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

int main(){
  // trabalhando com o ponto
  
  float X1, Y1;
  PONTO *P1;
  scanf("%f%f", &X1, &Y1);

  P1 = ponto_criar (X1, Y1);
  ponto_print (P1);
  ponto_apagar (P1);

  // trabalhando com o circulo todo

  float X2, Y2, R;
  PONTO *P2;
  CIRCULO *C1;
  scanf("%f%f%f", &X2, &Y2, &R);

  P2 = ponto_criar (X2, Y2);
  C1 = circulo_criar (P2, R);
  imprimir (C1, P2);
  //circulo_apagar (C1);

  return 0;
}
