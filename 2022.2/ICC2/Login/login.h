#ifndef _LOGIN_H
#define _LOGIN_H

	#include "lista.h"

	#define TAM_HASH 10 /// defino esse padrão, pois existirá um padrão na hora de armazenar no hash map

	typedef struct hash HASH;

	// definindo uma classe para o hash map:
	struct hash{
		LISTA *data;
	};

	HASH *criar_hash();
	void cadastrar(HASH *hash_map, char *N_USP);
	void login(HASH *hash_map, char *tentativa_NUSP, char *tentativa_senha);
	void imprimir_hash(HASH *hash_map);

#endif