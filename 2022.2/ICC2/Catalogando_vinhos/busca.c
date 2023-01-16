# include "busca.h"

FILE *ler_arquivo(char *nome_arquivo){
	FILE *arq;
	// abrindo somente para leitura
	arq = fopen(nome_arquivo, "r");

	if (arq == NULL){
		printf("Erro de leitura do arquivo\n");
	}
	return arq;
}

VINHO *cadastrar_vinhos(int *qtd_vinhos){
	printf("Digite o nome do arquivo(csv): ");
	char nome_arquivo[30];
	scanf("%s", nome_arquivo);

	// leitura do arquivo
  	FILE *arq = ler_arquivo(nome_arquivo);

  	// criando um vetor com alocação dinamica
  	VINHO *vinhos = calloc((*qtd_vinhos), sizeof(VINHO));

  	// antes de ler os dados do arquivo, ler a primeiira linha que nao me serve pra nada
  	char lixo[50];
  	fgets(lixo, 50, arq);

	// lendo os dados do arquivo
	while (!feof(arq)){
		// lendo os dados:
		fscanf(arq,"%d,", &vinhos[(*qtd_vinhos) - 1].ID);
    	fscanf(arq,"%lf,", &vinhos[(*qtd_vinhos) - 1].acido_citrico);
    	fscanf(arq,"%lf,", &vinhos[(*qtd_vinhos) - 1].acucar_residual);
    	fscanf(arq,"%lf,", &vinhos[(*qtd_vinhos) - 1].densidade);
    	fscanf(arq,"%lf,", &vinhos[(*qtd_vinhos) - 1].PH);
    	fscanf(arq,"%lf\n", &vinhos[(*qtd_vinhos) - 1].alcool);
    	(*qtd_vinhos)++;
    	vinhos = (VINHO*)realloc(vinhos,(*qtd_vinhos) * sizeof(VINHO));
    }
    fclose(arq);
    (*qtd_vinhos)--;
    vinhos = (VINHO*)realloc(vinhos,(*qtd_vinhos) * sizeof(VINHO));
    return vinhos;
}

void imprimir_vinho(int ID, VINHO *vinhos){
	printf("ID: %d,", vinhos[ID].ID);
	printf("Citric Acid: %.5lf, ", vinhos[ID].acido_citrico);
	printf("Residual Sugar: %.5lf, ", vinhos[ID].acucar_residual);
	printf("Density: %.5lf, ", vinhos[ID].densidade);
	printf("pH: %.5lf, ", vinhos[ID].PH);
	printf("Alcohol: %.5lf", vinhos[ID].alcool);
	printf("\n");
}

void imprimir_vinhos(VINHO *vinhos, int qtd_vinhos){
	for (int i = 0; i < qtd_vinhos; i++){
		imprimir_vinho(i, vinhos);
		printf("\n");
	}
}

void escolher_ordenacao(VINHO *vinhos, int qtd_vinhos){
	printf("Escolha o parametro que deseja ordenar: ");
	char nome_parametro[20];
	scanf("%s", nome_parametro);

	// criando as opções para o usuario escolher:
	char p1[20] = "ID";
	char p2[20] = "acido_citrico";
	char p3[20] = "acucar_residual";
	char p4[20] = "densidade";
	char p5[20] = "PH";
	char p6[20] = "alcool";

	if (strcmp(nome_parametro, p1) == 0){
		for (int i = 0; i < qtd_vinhos; i++){
			vinhos[i].aux = vinhos[i].ID ;
		}
	}
	else if(strcmp(nome_parametro, p2) == 0){
		for (int i = 0; i < qtd_vinhos; i++){
			vinhos[i].aux = vinhos[i].acido_citrico ;
		}
	}
	else if(strcmp(nome_parametro, p3) == 0){
		for (int i = 0; i < qtd_vinhos; i++){
			vinhos[i].aux = vinhos[i].acucar_residual;
		}
	}
	else if(strcmp(nome_parametro, p4) == 0){
		for (int i = 0; i < qtd_vinhos; i++){
			vinhos[i].aux = vinhos[i].densidade;
		}
	}
	else if(strcmp(nome_parametro, p5) == 0){
		for (int i = 0; i < qtd_vinhos; i++){
			vinhos[i].aux = vinhos[i].PH;
		}
	}
	else if(strcmp(nome_parametro, p6) == 0){
		for (int i = 0; i < qtd_vinhos; i++){
			vinhos[i].aux = vinhos[i].alcool;
		}
	}
	else{
		printf("Opcao invalida\n");
	}
}

// iniciar processo do merge sort:
void merge(VINHO *vinhos, int esq, int meio, int dir){
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
 
    // criando os vetores de strcit temporarios:
    VINHO *P1 = calloc(n1, sizeof(VINHO));
    VINHO *P2 = calloc(n2, sizeof(VINHO));
    
 
    // copiando as informações para os vetores temporarios:
    for (i = 0; i < n1; i++){
        P1[i] = vinhos[esq + i];
    }
    for (j = 0; j < n2; j++){
        P2[j] = vinhos[meio + 1 + j];
    }
 
    // Ordenando e recolocando no vetor original:
    i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (P1[i].aux <= P2[j].aux) {
            vinhos[k] = P1[i];
            i++;
        }
        else {
            vinhos[k] = P2[j];
            j++;
        }
        k++;
    }
 
    // Se sobrarem elementos em P1, colocar no vetor original:
    while (i < n1) {
        vinhos[k] = P1[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        vinhos[k] = P2[j];
        j++;
        k++;
    }
}

// função principal MergeSort:
void mergeSort(VINHO *vinhos, int esq, int dir){
    if (esq < dir) {
        // para evitar overflow
        int meio = esq + (dir - esq) / 2;
 
        mergeSort(vinhos, esq, meio);
        mergeSort(vinhos, meio + 1, dir);
 
        merge(vinhos, esq, meio, dir);
    }
}

// implementando a busca binaria:
// como queremos retornar o de menor indecie e tbm a quantidade de vinhos com essa caracteristiac, vou fazer uma função int que
// retorna o ID
int busca_binaria(VINHO *vinhos, int esq, int dir, double x){
    if (dir >= esq) {
        int meio = esq + (dir - esq) / 2;
 
        // se o elemento já estiver no meio:
        if (vinhos[meio].aux == x){
            return meio;
        }
 
        // se o elemento for menor:
        if (vinhos[meio].aux > x){
            return busca_binaria(vinhos, esq, meio - 1, x);
        }
        else{
        	// se for maior:
        	return busca_binaria(vinhos, meio + 1, dir, x);
        }
    }
    // caso o elemento não esteja contido no conjunto:
    return -1;
}

// verificando a quantidade de vinhos com essa caracteristica:
void qtd_encontrado(VINHO *vinhos, int esq, int dir){
	// sabendo qual o valor procurado:
	int total = 0;
	double procurado;
	printf("Digite o valor a ser procurado: ");
	scanf("%lf", &procurado);

	// fazendo a busca binaria:
	int ID_atual = busca_binaria(vinhos, esq, dir, procurado);
	if (ID_atual == -1){
		printf("Nenhum vinho encontrado\n");
	}
	else{
		int ID_esq = ID_atual - 1;
		int ID_dir = ID_atual + 1;
		total++;

		while (vinhos[ID_esq].aux == procurado){
			total++;
			ID_esq--;
		}
		while (vinhos[ID_dir].aux == procurado){
			total++;
			ID_dir++;
		}

		// no final, imprimir o de menor ID:
		if (vinhos[ID_esq + 1].aux == procurado){
			imprimir_vinho(ID_esq + 1, vinhos);
		}
		else{
			imprimir_vinho(ID_atual, vinhos);
		}
	}
	printf("Quantidade de vinhos encontrados: %d\n", total);
}