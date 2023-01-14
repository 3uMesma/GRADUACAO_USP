#ifndef _LISTA_H
#define _LISTA_H

	#include "cadastro.h"

	typedef struct lista LISTA;

	// criando as listas simplesmente encadeadas:
	struct lista{
		ALUNO *ini, *fim;
		int total;
	};

	LISTA *cria_lista();
	void insere(LISTA *l, ALUNO *novo_aluno);
	bool esta_na_lista_NUSP(LISTA *l, ALUNO *procurado);
	ALUNO *esta_na_lista_aluno(LISTA *l, ALUNO *procurado);
	void imprimir(LISTA *l);

#endif