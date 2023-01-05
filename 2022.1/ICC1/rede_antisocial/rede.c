#include "rede.h"
char **alocar_nomes(int qtt_nomes){
	char **matriz_nomes;
	matriz_nomes= (char **) calloc(qtt_nomes, sizeof(char *));

	if (matriz_nomes == NULL){
		printf("Erro de alocacao da matriz\n");
		return NULL;
	}

	for (int i = 0; i < qtt_nomes; i++){
		matriz_nomes[i] = (char *) calloc(100, sizeof(char));
		if (matriz_nomes[i] == NULL){
			for(int k = 0; k < i; k++){
				free(matriz_nomes[k]);
			}
			free(matriz_nomes);
			return NULL;
		}
	}
	return matriz_nomes;
}

int **alocar_inimizades(int qtt_nomes){
	int **matriz_inimizades;
	matriz_inimizades= (int **) calloc(qtt_nomes, sizeof(int *));

	if (matriz_inimizades == NULL){
		printf("Erro de alocacao da matriz\n");
		exit(1);
	}

	for (int i = 0; i < qtt_nomes; i++){
		matriz_inimizades[i] = (int *) calloc(100, sizeof(int));
		if (matriz_inimizades[i] == NULL){
			for(int k = 0; k < i; k++){
				free(matriz_inimizades[k]);
			}
			free(matriz_inimizades);
			exit(1);
		}
	}
	return matriz_inimizades;
}

void imprimir_mesmo_nome(char **matriz_nomes, char **matriz_sobrenomes, int qtt_nomes, int **matriz_inimizades){
	// verificando se tem nome repetido
	int flag = 0;
	for (int i = 0; i < qtt_nomes; i++){
		for (int j = i + 1; j < qtt_nomes; j++){
			if (strcmp(matriz_nomes[i], matriz_nomes[j]) == 0){
				//pegando os inimigos dos dois
				printf("Inimigos dos(as) %s(s)\n", matriz_nomes[i]);
				for (int k = 0; k < qtt_nomes; k++){
					if (matriz_inimizades[i][k] == 1 && matriz_inimizades[j][k] == 1){
						printf("%s %s\n", matriz_nomes[k], matriz_sobrenomes[k]);
						flag++;
					}
				}
				if (flag == 0){
					printf("Os %s(s) não tem inimigos em comum\n", matriz_nomes[i]);
				}

			}
		}
		flag = 0;
	}
}

void troca_inimizades(int qtt_nomes, int **matriz_inimizades){
	int id1, id2;
	printf("Digite o ID do usuario A: ");
	scanf("%d", &id1);
	printf("Digite o ID do usuario B: ");
	scanf("%d", &id2);

	// verificando se eh invalido
	if (id1 < 0 || id1 >= qtt_nomes){
		printf("ID do usuario A inexistente\n");
	}
	else if (id2 < 0 || id2 >= qtt_nomes){
		printf("ID do usuario B inexistente");
	}
	else if (id1 == id2){
		printf("O ID eh o mesmo. oeparaco invalida\n");
	}

	matriz_inimizades[id1][id2] = !(matriz_inimizades[id1][id2]);
	matriz_inimizades[id2][id1] = !(matriz_inimizades[id2][id1]);

}

void possiveis_amigos(char **matriz_nomes, char **matriz_sobrenomes, int qtt_nomes, int **matriz_inimizades){

	int inimizades[qtt_nomes], *possiveis_amizades;

	possiveis_amizades = (int *) calloc(qtt_nomes, sizeof(int));

	int qtt_inimizades = 0, m = 0;

	int id;
	printf("Digite o ID desejado: ");
	scanf("%d", &id);

	for (int i = 0; i < qtt_nomes; i++){
		if (matriz_inimizades[i][id] == 1){
			inimizades[qtt_inimizades] = i;
			qtt_inimizades++;
		}
	}

	// tendo as inimizades, agr ver quem eh inimigo dos inimigos
	for (int i = 0; i < qtt_inimizades; i++){
		for (int k = 0; k < qtt_nomes; k++){
			if (matriz_inimizades[inimizades[i]][k] == 1 && matriz_inimizades[id][k] != 1){
				possiveis_amizades[m] = k;
				m++;
				//tirando os repetidos;
				for (int l = 0; l < m; l++){
					if (possiveis_amizades[l] == possiveis_amizades[m]){
						m--;
					}
				}
			}
		}
	}

	printf("Os possiveis amigos de %s %s sao:\n", matriz_nomes[id], matriz_sobrenomes[id]);
	for (int i = 0; i < m; i++){
		printf("%s %s\n", matriz_nomes[possiveis_amizades[i]], matriz_sobrenomes[possiveis_amizades[i]]);
	}
}

void ordenar_sobrenome(char **matriz_nomes, char **matriz_sobrenomes, int qtt_nomes){

	char *auxiliar;

	for (int i = 1; i < qtt_nomes; i++) {
		for (int j = 1; j < qtt_nomes; j++) {
			if (strcmp(matriz_sobrenomes[j - 1], matriz_sobrenomes[j]) > 0) {
				int tamanho = strlen(matriz_sobrenomes[j - 1]);
				auxiliar = (char *) calloc(tamanho, sizeof(char));
				strcpy(auxiliar, matriz_sobrenomes[j - 1]);
				strcpy(matriz_sobrenomes[j - 1], matriz_sobrenomes[j]);
				strcpy(matriz_sobrenomes[j], auxiliar);
				free(auxiliar);
				// repetindo o processo pro nome ir junto, como eh so pra ordenar o sobrenome, tanto faz a ordem do nome
				int tamanho_nome = strlen(matriz_nomes[j- 1]);
				auxiliar = (char *) calloc(tamanho_nome, sizeof(char));
				strcpy(auxiliar, matriz_nomes[j - 1]);
				strcpy(matriz_nomes[j - 1], matriz_nomes[j]);
				strcpy(matriz_nomes[j], auxiliar);
				free(auxiliar);
      }
   }
}

	printf("A ordenacao por sobrenome eh a seguinte:\n ");
	for (int i = 0; i < qtt_nomes; i++){
		printf("%s %s\n", matriz_nomes[i], matriz_sobrenomes[i]);
	}
}


void desalocar_memoria_char(char **matriz, int qtt_nomes){
	for (int i = 0; i < qtt_nomes; i++){
		free(matriz[i]);
	}
	free(matriz);
}

void desalocar_memoria_int(int**matriz, int qtt_nomes){
	for (int i = 0; i < qtt_nomes; i++){
		free(matriz[i]);
	}
	free(matriz);
}