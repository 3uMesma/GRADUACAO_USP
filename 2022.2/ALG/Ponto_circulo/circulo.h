#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

typedef struct circulo_ CIRCULO;

CIRCULO *circulo_criar (PONTO *p, float raio);
bool circulo_set_ponto (CIRCULO *c, PONTO *p);
bool circulo_set_raio (CIRCULO *c, float raio);
PONTO *circulo_get_ponto (CIRCULO *c, PONTO *P);
int circulo_get_raio (CIRCULO *c, float *raio);
void circulo_apagar (CIRCULO *circulo);
void imprimir (CIRCULO *C, PONTO *P);

#endif