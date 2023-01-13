#include <stdio.h>
#include <stdlib.h>

int *aloca(double tam){
    int *vetor;
    vetor = (double*)malloc(tam * sizeof(double));//alocacao malloc de acordo com a qtde entrada
    if(vetor == NULL){
        printf("Erro de alocacao\n");
    }
    for(int i = 0; i  < tam; i++){//guarda a ordem dos valores de entrada
        scanf("%d", &vetor[i]);
    }
    return vetor;
}

int mergejunta(double *vetor, int inicio, int meio, int fim){
	double *vetor_aux;
  int qtde_trocas = 0;
  vetor_aux = (double*) malloc(((fim-inicio)+1) * sizeof(double));//alocacao do vetor auxiliar

	int i = inicio;//indice do primeiro elemento da primeira lista
	int j = meio+1;//indice do primeiro elemento da segunda lista
	int k = 0;//indice para o vetor auxiliar


	while(i <= meio && j <= fim){//compara e intercala os valores de ambas as listas
		if (vetor[i] <= vetor[j]){//verifica se o valor onde se aponta na primeira lista possui menor em comparacao ao da outra lista
			vetor[k] = vetor[i];//se sim, insere o da primeira lista no vetor aux
			i++;//proximo elemento da primeira lista
		} else{
        qtde_trocas += j-(inicio+k);
			  vetor_aux[k] = vetor[j];//se nao, insere o da segunda lista no vetor aux
			  j++;//proximo elemento da segunda lista
		}
		k++;
	}

	while(i <= meio){//caso tenha acabado na segunda lista, verifica se sobrou algum valor da primeira
		vetor_aux[k] = vetor[i];//caso sim, insere o resto no vetor aux
		i++;
		k++;
	}

	while(j <= fim){//caso tenha acabado na primeira lista, verifica se sobrou algum valor da segunda
		vetor_aux[k] = vetor[j];//caso sim, insere o resto no vetor aux
		j++;
		k++;
	}

	for(i = inicio, k = 0; i <= fim; i++,k++)//atualiza o vetor principal pelo vetor aux
		vetor[i] = vetor_aux[k];

	free(vetor_aux);//desaloca o vetor aux
    return qtde_trocas;
}

int mergesort(double *vetor, int inicio, int fim){
	if (fim <= inicio) 
        return 0;

	int meio = (int)((inicio+fim)/2);
	int valor1 = mergesort(vetor, inicio, meio);
	int valor2 = mergesort(vetor, meio+1, fim);
  int valor3 = mergejunta(vetor, inicio, meio, fim);

  return valor1+valor2+valor3;
}

// objetivo: imprimir tudo
void print(double *vetor, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%.2lf ", vetor[i]);
  }
  printf("\n");
}

int main(){
  int tam;
  double *vetor;
  scanf("%d", &tam);
  vetor = (double*) malloc(tam * sizeof(double));
  int lixo1, lixo2;
  scanf("%d %d", &lixo1, &lixo2);
  
  // adicionando cada elemento ao vetor
  for (int i = 0; i < tam; i++){
    scanf("%d", &vetor[i]);
  }

  // fazendo a ordenação e imprimindo
  mergesort(vetor, 0, tam - 1);
  print(vetor, tam);
}
