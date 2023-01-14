#ifndef _CADASTRO_H
#define _CADASTRO_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>
	#include <math.h>
	#include <stdbool.h>

	#define TAM_NOTAS 4
	#define TAM_NUSP 8 // pois por padrão o número USP possui sempre oito dígitos

	typedef struct aluno ALUNO;

	// dados de cada aluno:
	struct aluno{
		char *NUSP; // chave do HASHMAP
		unsigned int senha;
		double notas[TAM_NOTAS];
		ALUNO *proximo; // guardando a informação do pŕoximo para a lista encadeada
	};

	ALUNO *cadastrar_aluno(char *N_USP);
	void imprimir_aluno(ALUNO *aluno);
	int str_to_int(char *NUSP);
	unsigned int criptografar(char *senha, int tam_senha);
	bool comparar_alunos(ALUNO *aluno1, ALUNO *aluno2);
	void printar_notas(ALUNO *aluno);
	void string_struct(char *N_USP, ALUNO *aluno);
	ALUNO *cadastrar_parte_aluno(char *N_USP, char *senha);

#endif