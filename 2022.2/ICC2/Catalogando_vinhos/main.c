# include "busca.h"

int main(){
	// fazendo a leitura
	int qtd_vinhos = 1;
	VINHO *vinhos;
	vinhos = cadastrar_vinhos(&qtd_vinhos);

	int qtd_buscas;
	printf("Digite a quantidade de buscas a serem realizadas: ");
	scanf("%d", &qtd_buscas);

	for (int i = 0; i < qtd_buscas; i++){
		// método de ordenação
		escolher_ordenacao(vinhos, qtd_vinhos);
		mergeSort(vinhos, 0, qtd_vinhos - 1);
		// fazendo a busca:
		qtd_encontrado(vinhos, 0, qtd_vinhos - 1);
	}
	return 0;
}