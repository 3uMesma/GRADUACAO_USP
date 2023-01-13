#include "ferramentas.h"

int main(){
	int opcao = -1;
	int largura = 0, altura = 0;
	float **matriz;
	menu();
	while(opcao != 0){
		scanf("%d", &opcao);
		switch (opcao){
			case 1:
				// abrindo o arquivo:
				FILE *arq;
				printf("Digite o nome do arquivo: ");
				char nomearquivo[100];
				scanf("%s",nomearquivo);
				arq = fopen(nomearquivo, "r");

				// caso o arquivo nao exista:
				if (arq == NULL){
					printf("Erro de leitura do arquivo [%s]\n",nomearquivo);
					exit(1);
				}
				fscanf(arq, "%d %d", &largura, &altura);

				// alocando memoria pra armazenar a imagem:
				matriz = (float**) malloc (altura * sizeof (float*));
				for (int i = 0; i < altura; i++){
					matriz[i] = (float*) malloc (largura * sizeof (float)) ;
				}

				// lendo as informações e armazenando:
				for (int i = 0; i < altura; i++){
					for (int j = 0; j < largura; j++){
						fscanf(arq, "%f", &matriz[i][j]);
					}
				}

				// fechando o arquivo e retornando a matriz:
				fclose(arq);
				//imprimir_matriz(matriz, altura, largura);
				printf("Arquivo lido com sucesso\n");
				break;
			case 2:
				float brilho;
				printf("Digite o brilho desejado(em decimal): ");
				scanf("%f", &brilho);

				novo_brilho(matriz, altura, largura, brilho);
				printf("Brilho atualizado\n");
				break;
			case 3:
				int direcao;
				printf("Digite 1 para horizontal e 2 para vertical: ");
				scanf("%d", &direcao);

				inverter(matriz, altura, largura, direcao);
				break;
			case 4:
				int sentido;
				printf("Digite 1 para esquerda e 2 para direita: ");
				scanf("%d", &sentido);

				matriz = rotacionar(matriz, altura, largura, sentido);
				int temp = largura;
				largura = altura;
				altura = temp;
				printf("Imagem rotacionada\n");
				break;
			case 5:
				float escala;
				printf("Digite a escala desejada(em decimal): ");
				scanf("%f", &escala);

				matriz = redimensionar(matriz, altura, largura, escala);
				altura = altura * escala;
				largura = largura * escala;
				printf("Imagem redimensionada\n");
				break;
			case 6:
				// salvar
				FILE *arq_final;
				char nomearquivofinal[100];
				printf("Digite o nome do arquivo final: ");
				scanf("%s",nomearquivofinal);
				arq_final = fopen(nomearquivofinal, "w");

				if (arq_final == NULL){
					printf("Erro de leitura do arquivo final [%s]\n",nomearquivofinal);
					exit(1);
				}

				fprintf(arq_final, "%d %d\n", largura, altura);

				for (int i = 0; i < altura; i++){
					for (int j = 0; j < largura; j++){
						fprintf(arq_final, "%f ", matriz[i][j]);
					}
					fprintf(arq_final, "\n");
				}

				printf("Arquivo salvo com sucesso\n");
				fclose(arq_final);
				break;
			case 0:
				// sair
				printf("Obrigada por usar o nosso programa!\n");
				return 0;
		}
	}
	return 0;
}