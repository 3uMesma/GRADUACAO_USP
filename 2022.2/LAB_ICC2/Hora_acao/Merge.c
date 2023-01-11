#include <stdio.h>
#include <stdlib.h>

int *aloca(int qtde_entrada){
    int *vetor_gomas;
    vetor_gomas = (int *)malloc(qtde_entrada * sizeof(int));//alocacao malloc de acordo com a qtde entrada
    if(vetor_gomas == NULL){
        printf("Erro de alocacao\n");
    }
    for(int i = 0; i<qtde_entrada; i++){//guarda a ordem dos valores de entrada
        scanf("%d", &vetor_gomas[i]);
    }
    return vetor_gomas;
}

int mergejunta(int *vetor_gomas, int inicio, int meio, int fim){
	int *vetor_aux, qtde_trocas = 0;
    vetor_aux = (int*) malloc(((fim-inicio)+1) * sizeof(int));//alocacao do vetor auxiliar

	int i = inicio;//indice do primeiro elemento da primeira lista
	int j = meio+1;//indice do primeiro elemento da segunda lista
	int k = 0;//indice para o vetor auxiliar


	while(i <= meio && j <= fim){//compara e intercala os valores de ambas as listas
		if (vetor_gomas[i] <= vetor_gomas[j]){//verifica se o valor onde se aponta na primeira lista possui menor em comparacao ao da outra lista
			vetor_aux[k] = vetor_gomas[i];//se sim, insere o da primeira lista no vetor aux
			i++;//proximo elemento da primeira lista
		} else{
            qtde_trocas += j-(inicio+k);
			vetor_aux[k] = vetor_gomas[j];//se nao, insere o da segunda lista no vetor aux
			j++;//proximo elemento da segunda lista
		}
		k++;
	}

	while(i <= meio){//caso tenha acabado na segunda lista, verifica se sobrou algum valor da primeira
		vetor_aux[k] = vetor_gomas[i];//caso sim, insere o resto no vetor aux
		i++;
		k++;
	}

	while(j <= fim){//caso tenha acabado na primeira lista, verifica se sobrou algum valor da segunda
		vetor_aux[k] = vetor_gomas[j];//caso sim, insere o resto no vetor aux
		j++;
		k++;
	}

	for(i = inicio, k = 0; i <= fim; i++,k++)//atualiza o vetor principal pelo vetor aux
		vetor_gomas[i] = vetor_aux[k];

	free(vetor_aux);//desaloca o vetor aux
    return qtde_trocas;
}

int mergesort(int *vetor_gomas, int inicio, int fim){
	if (fim <= inicio) 
        return 0;

	int meio = (int)((inicio+fim)/2);
	int valor1 = mergesort(vetor_gomas, inicio, meio);
	int valor2 = mergesort(vetor_gomas, meio+1, fim);
    int valor3 = mergejunta(vetor_gomas, inicio, meio, fim);

    return valor1+valor2+valor3;
}

void calcula_ganhador(int qtde_entrada, int *vetor_gomas){
    int qtde_trocas;
    qtde_trocas = mergesort(vetor_gomas, 0, qtde_entrada-1);
    //for(int i = 0; i< qtde_entrada; i++){
    //    printf("%d\n", vetor_gomas[i]);
    //}
    
    if(qtde_trocas%2 == 1){//caso seja impar as trocas, Jaques ganha, senao Fino ganha
        printf("Jaques\n");
    } else {
        printf("Fino\n");
    }
}

int main(){
    int qtde_entrada, *vetor_gomas;
    do{
        scanf("%d", &qtde_entrada);//pega qtde entrada
        if(qtde_entrada != 0){
            vetor_gomas = aloca(qtde_entrada);//funcao de alocacao de vetor
            calcula_ganhador(qtde_entrada, vetor_gomas);//funcao que calcula quem ganhou por merge
            free(vetor_gomas);
        }
    }while(qtde_entrada != 0);

    return 0;
}
