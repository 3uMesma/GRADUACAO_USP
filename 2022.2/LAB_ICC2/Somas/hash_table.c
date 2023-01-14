#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int calcula_hash(int valor, int colisao, int tam_vetor){//funcao de calculo do hash
    return (valor+colisao) % tam_vetor;
}

void insereHash(int *vetor_hash, int tam_vetor, int valor){//funcao de insercao do valor na tabela hash
    int colisao = 0;
    do{//enquanto nao encontrar uma posicao para insercao continua a recursao para insercao do valor
        int posicao = calcula_hash(valor, colisao, tam_vetor);
        if(vetor_hash[posicao] == -1){
            vetor_hash[posicao] = valor;
            break;
        } else{
            colisao++;
        }
    }while(1);
}

bool buscaHash(int *vetor_hash, int tam_vetor, int valor_pesquisa){//funcao de busca do valor par no vetor hash
    int colisao = 0;
	int posicao = calcula_hash(valor_pesquisa, colisao, tam_vetor);

    while(vetor_hash[posicao] != -1){	
		if (vetor_hash[posicao] == valor_pesquisa){
			return true;
		}
		posicao = calcula_hash(valor_pesquisa, colisao++, tam_vetor);
	}
    return false;
}

int main(){
    int num_entrada, valor, num_pesquisa, *vetor_hash;
    scanf("%d", &num_entrada);

    int tam_vetor = num_entrada*2;//atribuicao do tamanho do vetor hash

    vetor_hash = (int *)malloc(tam_vetor * sizeof(int));//alocacao do vetor hash
    if(vetor_hash == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    for(int i = 0; i<tam_vetor; i++){//atribuicao de valor -1 para todo o vetor hash
        vetor_hash[i] = -1;
    }

    int vetor_valores[num_entrada];//criacao do vetor de numeros de entrada
    for(int i = 0; i<num_entrada; i++){//insercao da entrada de numeros no vetor de valores e no vetor hash
        scanf("%d", &valor);
        vetor_valores[i] = valor;
        insereHash(vetor_hash, tam_vetor, valor);
    }

    int valor_pesquisa;
    scanf("%d", &num_pesquisa);
    for(int i = 0; i<num_pesquisa; i++){//pesquisa dos valores par no vetor hash
        scanf("%d", &valor);
        for(int j = 0; j<num_entrada; j++){//enquanto nao encontar um par para todos os valores que entraram no vetor
            valor_pesquisa = valor - vetor_valores[j];//pesquisa qual seria o par
            if(valor_pesquisa > 0 && buscaHash(vetor_hash, tam_vetor, valor_pesquisa)){//verifica o par tem condicao de existencia e se ele existe no vetor hash
                printf("S\n");
                break;
            }
            if(j+1 == num_entrada){//caso onde nao houve par que correspondesse ao valor procurado
                printf("N\n");
            }
        }
    }

    free(vetor_hash);//liberacao de memoria do vetor hash
    return 0;
}
