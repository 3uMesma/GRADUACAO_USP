#include "lista.h"

// objetivo: criar a lista
LISTA *cria_lista() {
	LISTA *p = (LISTA *)malloc(sizeof(LISTA));
	p->ini = NULL;
	p->fim = NULL;
	p->total = 0;
	return p;
}

// objetivo: inserir um elemento na lista:
void insere(LISTA *l, ALUNO *novo_aluno) {
	assert(l != NULL);
	
	ALUNO *p = l -> ini;
	ALUNO *ant = NULL;
	while(p != NULL && str_to_int(novo_aluno -> NUSP) > str_to_int(p-> NUSP)) {
		ant = p;
		p = p -> proximo;
	}
	
	if(l -> ini == NULL) { //ou l->fim == NULL ou l->total == 0 (lista vazia)
		l -> ini = novo_aluno;
		l -> fim = novo_aluno;
	} else if(p == l -> ini){ //insercao no inicio da lista
		novo_aluno -> proximo = p;
		l -> ini = novo_aluno;
	} else if(p == NULL) { //insercao no fim da lista
		l -> fim -> proximo = novo_aluno;
		l -> fim = novo_aluno;
	} else { //insercao meio da lista
		novo_aluno -> proximo = ant -> proximo;
		ant -> proximo = novo_aluno;
	}
	
	l->total++;
}

// objetivo: buscar um NUSP na lista
bool esta_na_lista_NUSP(LISTA *l, ALUNO *procurado) {
	assert(l != NULL);
	ALUNO *p = l -> ini;
	
	while(p != NULL && str_to_int(procurado -> NUSP) > str_to_int(p-> NUSP)) {
		p = p -> proximo;
	}
	
	if(p == NULL) { // nao encontrou o elemento
		return false;
	} else if(str_to_int(procurado -> NUSP) == str_to_int(p-> NUSP)){
		return true;
	} else {
		return false;
	}
}

// objetivo: encontrar um aluno na lista e puxá-lo
ALUNO *esta_na_lista_aluno(LISTA *l, ALUNO *procurado) {
	assert(l != NULL);
	ALUNO *p = l -> ini;
	
	while(p != NULL && str_to_int(procurado -> NUSP) > str_to_int(p-> NUSP)) {
		p = p -> proximo;
	}
	
	if(p == NULL) { // nao encontrou o elemento
		return NULL;
	} else if(comparar_alunos(procurado, p) == true){
		return p;
	} else {
		return NULL;
	}
}

// objetivo: imprimir a lista
void imprimir(LISTA *l) {
	assert(l != NULL);
	ALUNO *p = l->ini;
	
	while(p != NULL) {
		printf("%s ", p -> NUSP);
		p = p->proximo;
	}
	printf("\n");
}