# include "cadastro_alunos.h"

double media(int *notas, int qtd_notas){
	double soma = 0.0;
	for (int i = 0; i < qtd_notas; i++){
		soma += notas[i];
	}
	double media_final = soma/qtd_notas;
	return media_final;
}

// objetivo: fazer o cadastro de todos os alunos:
ALUNO *cadastrar_alunos(int qtd_alunos, int qtd_notas){
	// alocando espaço para o vetor de struct e suas informações:
	ALUNO *alunos = (ALUNO*) malloc(qtd_alunos * sizeof(ALUNO));
	for (int i = 0; i < qtd_alunos; i++){
		alunos[i].nome = (char*) malloc(20 * sizeof(char));
		alunos[i].notas = (int*) malloc(qtd_notas * sizeof(int));

		// lendo as informações:
		printf("Digite o nome do aluno: ");
		scanf("%s", alunos[i].nome);
		printf("Digite as notas: ");
		for (int j = 0; j < qtd_notas; j++){
			scanf("%d", &alunos[i].notas[j]);
		}

		// calculando a media:
		alunos[i].media = media(alunos[i].notas, qtd_notas);
	}

	// vetor de struct pronto:
	return alunos;
}

// objetivo: imprimir todos os alunos
void imprimir_alunos(ALUNO *alunos, int qtd_alunos, int qtd_notas){
	for (int i = 0; i < qtd_alunos; i++){
		printf("Nome: %s\n", alunos[i].nome);
		printf("Media: %.3lf\n", alunos[i].media);
		for (int j = 0; j < qtd_notas; j++){
			printf("Nota %d: %d\n", j, alunos[i].notas[j]);
		}
		printf("\n");
	}
}

// objetivo: realizar a troca entre dois alunos
void troca(ALUNO *a, ALUNO *b, int qtd_notas){
	// trocando o nome:
	char *nome_aux = (char*) malloc(20 * sizeof(char));
	strcpy(nome_aux, a -> nome);
	strcpy(a -> nome, b -> nome);
	strcpy(b -> nome, nome_aux);

	// trocando a media
	double aux_media = a -> media;
	a -> media = b -> media;
	b -> media = aux_media;

	// trocando as notas:
	for (int i = 0; i < qtd_notas; i++){
		int aux_nota = a -> notas[i];
		a -> notas[i] = b -> notas[i];
		b -> notas[i] = aux_nota;
	}

}

//  objetivo: comparar dois alunos
bool compara (ALUNO *a, ALUNO *b, int qtd_notas){
	// verifica se o aluno a é melhor que o aluno b:
	if (a -> media > b -> media)return true;
	if (a -> media < b -> media)return false;
	for (int i = 0; i < qtd_notas; i++){
		if (a -> notas[i] > b -> notas[i])return true;
	}
	// caso contrário:
	return false;
}

// realizar o processo de haepify em uma subarvore
void heapify(ALUNO *alunos, int qtd_alunos, int ID_melhor, int qtd_notas){
    // achar o melhor entre a raiz e seus dois filhos
 
    // Inicializar o melhor como a raiz:
    int melhor = ID_melhor;
    int esq = 2 * ID_melhor + 1;
    int dir = 2 * ID_melhor + 2;
 
    // se o filho da esquerda for maior que o pai:
    if (esq < qtd_alunos && compara(&alunos[esq], &alunos[melhor], qtd_notas) == false){
    	melhor = esq;
    }
 
    // se o filho da direita for maior que o pai:
    if (dir < qtd_alunos && compara(&alunos[dir], &alunos[melhor], qtd_notas) == false){
    	melhor = dir;
    }

    // Se o melhor ainda não for a raiz, continuar o processo:
    if (melhor != ID_melhor) {
 
        troca(&alunos[ID_melhor], &alunos[melhor], qtd_notas);
 
        // Refazendo o processoheapfy recursivamente:
        heapify(alunos, qtd_alunos, melhor, qtd_notas);
    }
}

// objetivo: função principal do heap sort
void heapSort(ALUNO *alunos, int qtd_alunos, int qtd_notas){
    // Criar o maxheap
    for (int i = qtd_alunos / 2 - 1; i >= 0; i--){
    	heapify(alunos, qtd_alunos, i, qtd_notas);
    }
 
    // Heap sort
    for (int i = qtd_alunos - 1; i >= 0; i--) {
        troca(&alunos[0], &alunos[i], qtd_notas);
 
        // Heapify a raiz para ter o maior elemento nela
        heapify(alunos, i, 0, qtd_notas);
    }
}
