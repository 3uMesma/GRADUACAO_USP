#include "ferramentas.h"

// objetivo: formatar o menu
void menu(){
	printf("/tMENU\n");
	printf("[1] Nova imagem\n");
	printf("[2] Brilho da imagem\n");
	printf("[3] Inverter imagem\n");
	printf("[4] Rotacionar a imagem\n");
	printf("[5] Redimensionar imagem\n");
	printf("[6] Salvar imagem\n");
	printf("[0] Sair\n");
}

// objetivo: imprimir o estado atual da matriz
void imprimir_matriz(float **matriz, int altura, int largura){
	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			printf("%.2f ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void novo_brilho(float **matriz, int altura, int largura, float brilho){
	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			float aux = brilho * matriz[i][j];
			if (aux > 1){
				matriz[i][j] = 1;
			}
			else{
				matriz[i][j] = aux;
			}
		}
	}
}

void apagar(float **matriz, int altura){
	for (int i = 0; i < altura; i++){
		free(matriz[i]);
	}
	free(matriz);
}

float **copiar(float **matriz, int altura, int largura){
	float **aux;
	aux = (float**) malloc (altura * sizeof (float*));
	for (int i = 0; i < altura; i++){
		aux[i] = (float*) malloc (largura * sizeof (float)) ;
	}

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			aux[i][j] = matriz[i][j];
		}
	}
	return aux;
}

void inverter(float **matriz, int altura, int largura, int direcao){
	if (direcao != 1 && direcao != 2){
		printf("Caractere invalido\n");
		return;
	}

	if (direcao == 1){
		for (int i = 0; i < altura; i++){
			for (int j = 0; j < largura/2; j++){
				float aux = matriz[i][j];
				matriz[i][j] = matriz[i][largura - j - 1];
				matriz[i][largura - j - 1] = aux;
			}
		}
	}
	else if (direcao == 2){
		for (int i = 0; i < altura/2; i++){
			for (int j = 0; j < largura; j++){
				float aux = matriz[i][j];
				matriz[i][j] = matriz[altura - i - 1][j];
				matriz[altura - i - 1][j] = aux;
			}
		}
	}
	printf("Imagem invertida\n");
}

float **realocar_matriz(float **matriz, int velha_altura, int nova_altura, int nova_largura){
	// free na matriz toda:
	apagar(matriz, velha_altura);

	// alocar com o novo tamanho:
	float **nova_matriz;
	nova_matriz = (float**) malloc (nova_altura * sizeof (float*));
	for (int i = 0; i < nova_altura; i++){
		nova_matriz[i] = (float*) malloc (nova_largura * sizeof (float)) ;
	}

	return nova_matriz;

}

float **rotacionar(float **matriz, int altura, int largura, int sentido){
	// armazenar toda a info em uma matriz auxiliar
	float **aux = copiar(matriz, altura, largura);

	// realocando a matriz original:
	matriz = realocar_matriz(matriz, altura, largura, altura);

	// verificando o sentido da rotação:
	if (sentido == 1){
		for (int i = 0; i < altura; i++){
			for (int j = 0; j < largura; j++){
				matriz[j][i] = aux[i][largura - j - 1];
			}
		}
	}
	else if(sentido == 2){
		for (int i = 0; i < altura; i++){
			for (int j = 0; j < largura; j++){
				matriz[j][i] = aux[altura - i - 1][j];
			}
		}
	}
	else{
		printf("Caractere não reconhecido\n");
		apagar(aux, altura);
	}
	apagar(aux, altura);
	return matriz;
}

float **redimensionar(float **matriz, int altura, int largura, float escala){
	// armazenar toda a info em uma matriz auxiliar
	float **aux = copiar(matriz, altura, largura);

	// realocar a matriz
	int nova_altura = altura * escala;
	int nova_largura = largura * escala;
	matriz = realocar_matriz(matriz, altura, nova_altura, nova_largura);

	for (int i = 0; i < nova_altura; i++){
    	for (int j = 0; j < nova_largura; j++){
        	matriz[i][j] = aux[(int) (i / escala)][(int) (j / escala)];
    	}
	}
	apagar(aux, altura);
	return matriz;
}