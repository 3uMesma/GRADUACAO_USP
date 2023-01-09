#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

typedef struct ponto_ {
  float ponto_x, ponto_y;
}PONTO;

PONTO *ponto_criar (float x, float y){
  PONTO *P = (PONTO *)malloc(sizeof(PONTO));
	if(P == NULL) {
		printf("Erro de alocação de memoria\n");
		return NULL;
	}
  
	P-> ponto_x = x;
	P-> ponto_y = y;
	
	return P;
}

void ponto_apagar (PONTO *P){
  if(P != NULL) {
		free(P);
	}
}

bool ponto_set (PONTO *P, float x, float y){
  if(P != NULL) {
    P -> ponto_x = x;
	  P -> ponto_y = y;
	}

  return 0;
}

float ponto_get_x (PONTO *P){
  if(P != NULL) {
    return P -> ponto_x;
	}
}

float ponto_get_y (PONTO *P){
  if(P != NULL) {
    return P -> ponto_y;
	}
}

void ponto_print (PONTO *P){
  if(P != NULL) {
		printf("Ponto: (%.1f, %.1f)\n", P->ponto_x, P->ponto_y);
	}
}