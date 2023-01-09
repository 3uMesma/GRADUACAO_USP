#ifndef PONTO_H
#define PONTO_H

#include <stdbool.h>

typedef struct ponto_ PONTO;

PONTO *ponto_criar (float x, float y);
void ponto_apagar (PONTO *P);
bool ponto_set (PONTO *P, float x,
float y);
float ponto_get_x (PONTO *P);
float ponto_get_y (PONTO *P);
float dist_dois_pontos(PONTO *P1, PONTO *P2);
void ponto_print (PONTO *P);

#endif