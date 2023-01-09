#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

typedef struct circulo_ {
  PONTO * P;
  float raio;
}CIRCULO;

CIRCULO *circulo_criar (PONTO *P, float raio){
  if (raio <= 0){
    printf("Esse circulo não existe\n");
    return NULL;
  }

  CIRCULO *C = (CIRCULO *)malloc(sizeof(CIRCULO));
	if(C == NULL) {
		printf("Erro de alocação de memoria\n");
		return NULL;
	}
  
	C -> P = P;
	C-> raio = raio;
	
	return C;
}

bool circulo_set_ponto (CIRCULO *C, PONTO *P){
  if(C != NULL) {
    C -> P = P;
	}
}

bool circulo_set_raio (CIRCULO *C, float raio){
  if(C != NULL) {
    C -> raio = raio;
	}
}

PONTO *circulo_get_ponto (CIRCULO *C, PONTO *P){
  if(C != NULL) {
    C -> P = C -> P;
	}
}

int circulo_get_raio (CIRCULO *C, float *raio){
  if(C != NULL) {
    *raio = C -> raio;
	}
}

void circulo_apagar (CIRCULO **circulo){
  if(circulo != NULL) {
		free(circulo);
	}
}

void imprimir (CIRCULO *C, PONTO *P){
if (C != NULL){
  float centro_x = ponto_get_x (P);
  float centro_y = ponto_get_y (P);
  printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f\n", centro_x, centro_y, C->raio);
  }
}