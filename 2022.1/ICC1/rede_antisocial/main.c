#include "rede.h"

int main(){
	FILE *arq;
	char **matriz_nomes;
	char **matriz_sobrenomes;
	int **matriz_inimizades;
	int opcao;
	int qtt_nomes;
	char nome[TAM_MAX], sobrenome[TAM_MAX];
	int id_atual, indice;

	do{
		printf("MENU:\n");
		printf("[1] Ler arquivo de dados\n");
		printf("[2] Imprimir inimizades com nomes em comum\n");
		printf("[3] Converter as inimizades\n");
		printf("[4] Identificar possiveis amigos\n");
		printf("[5] Ordenar pessoas conforme sobrenome\n");
		printf("[6] Salvar arquivo de dados\n");
		printf("[0] Sair\n");
		printf("Informa a operacao desejada: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
			arq = fopen("entrada.txt", "r");
			if (arq == NULL){
				printf("Erro de leitura do arquivo\n");
				exit(1);
			}

			fscanf(arq, "%d\n", &qtt_nomes);

			// lendo os nomes e sobrenomes;
			matriz_nomes = alocar_nomes(qtt_nomes);
			if (matriz_nomes == NULL){
				fclose(arq);
				exit(1);
			}
			matriz_sobrenomes = alocar_nomes(qtt_nomes);
			if (matriz_sobrenomes == NULL){
				fclose(arq);
				exit(1);
			}

			for (int i = 0; i < qtt_nomes; i++){
					fscanf(arq, "%d %s %s\n", &id_atual, &nome, &sobrenome);
					strcpy(matriz_nomes[id_atual], nome);
					strcpy(matriz_sobrenomes[id_atual], sobrenome);
			}

			matriz_inimizades = alocar_inimizades(qtt_nomes);
			if (matriz_inimizades == NULL){
				fclose(arq);
				exit(1);
			}

			for (int i = 0; i < qtt_nomes; i++){
				for (int j = 0; j < qtt_nomes; j++){
					fscanf(arq, "%d ", &indice);
					matriz_inimizades[i][j] = indice;
				}
			}

			fclose(arq);
			break;

			case 2:
			imprimir_mesmo_nome(matriz_nomes, matriz_sobrenomes, qtt_nomes, matriz_inimizades);
			break;

			case 3:
			troca_inimizades(qtt_nomes, matriz_inimizades);
			break;

			case 4:
			possiveis_amigos(matriz_nomes, matriz_sobrenomes, qtt_nomes, matriz_inimizades);
			break;

			case 5:
			ordenar_sobrenome(matriz_nomes, matriz_sobrenomes, qtt_nomes);
			break;

			case 6:
			arq = fopen("entrada.txt", "w");
			if (arq == NULL){
				printf("Erro de leitura do arquivo\n");
				exit(1);
		}
			fprintf(arq, "%d\n", qtt_nomes);


			for (int i = 0; i < qtt_nomes; i++){
					fprintf(arq, "%d %s %s\n", i, matriz_nomes[i], matriz_sobrenomes[i]);
			}

			fprintf(arq, "\n");

			for (int i = 0 ; i < qtt_nomes; i++){
				for (int j = 0; j < qtt_nomes; j++){
					fprintf(arq, "%d ", matriz_inimizades[i][j]);
				}
				fprintf(arq, "\n");
			}
				fprintf(arq, "\n");

				fclose(arq);
				break;

				case 0:
				printf("Tchau tchau\n");
				desalocar_memoria_char(matriz_nomes, qtt_nomes);
				desalocar_memoria_char(matriz_sobrenomes, qtt_nomes);
				desalocar_memoria_int(matriz_inimizades, qtt_nomes);
				exit(1);
				break;

				default:
				printf("Numero invalido.\n");
				break;

		}
	}while(opcao != 0);
}
