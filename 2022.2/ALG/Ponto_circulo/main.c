#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
#include "ponto.h"

int main(){

  // trabalhando com o circulo todo

  float X1, Y1, R;
  PONTO *P1;
  CIRCULO *C1;
  scanf("%f%f%f", &X1, &Y1, &R);

  P1 = ponto_criar (X1, Y1);
  C1 = circulo_criar (P1, R);

  // lendo os pontos
  int qtt;
  scanf("%d", &qtt);
  float X2, Y2;
  PONTO *P2;
  float dist;

  for (int i = 0; i < qtt; i++){
    scanf("%f%f", &X2, &Y2);
    P2 = ponto_criar (X2, Y2);
    dist = dist_dois_pontos(P1, P2);
    if (dist > R){
      printf("fora\n");
    }
    else if(dist == R){
      printf("no raio\n");
    }
    else{
      printf("dentro\n");
    }
  }

  
  ponto_apagar(P1);
  circulo_apagar(C1);

  return 0;
}
