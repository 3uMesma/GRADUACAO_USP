#include "ag.h"

// objetivo: criar uma função para guardar as constantes:
int *ler_const(){
  int *vetor = (int*) malloc(6 * sizeof(int));
  for (int i = 0; i < 6; i++){
    printf("Digite o valor de %c: ", 97 + i);
    scanf("%d", &vetor[i]);
  }
  return vetor;
}

// objetivo: criar uma lista de numeros aleatorios de tamanho n:
void aleatorios(int tam, CANDIDATO *geracao){
  for (int i = 0; i < tam; i++){
    // os aleatorios poderao ser negativos ou positivos
    int sinal = rand() % 2;
    geracao[i].numero = rand();
    if (sinal == 1){
      geracao[i].numero = geracao[i].numero * (-1);
    }
  }
}

int potencia(int base, int expoente){
  int resultado = 1;
  while (expoente > 0){
    resultado *= base;
    expoente--;
  }
  return resultado;
}

// objetivo: fazer o calculo da equação:
int resultado_final(int elemento, int *constantes){
  int resultado = 0;
  for (int i = 0; i < 6; i++){
    resultado += constantes[i] * potencia(elemento, 5 - i);
  }
  return abs(resultado);
}

// objetivo: calcular o fitness de cada valor
void calcular_fitness(int tam, CANDIDATO *geracao, int *constantes){
  for (int i = 0; i < tam; i++){
    geracao[i].fitness = resultado_final(geracao[i].numero, constantes);
  }
}

// objetivo: tranformar decimal em binario
int *dec_bin(int n){
  int *bin = (int*) malloc(32 * sizeof(int));
  int i = 0;
  while (n > 0) {
    bin[i] = n % 2;
    n = n / 2;
    i++;
  }
  return bin;
}

// objetivo: transformar binario em decimal
int bin_dec(int *vetor){
  int decimal = 0;
  int base = 1;
  for (int i = 31; i >= 0; i--) {
    decimal += vetor[i] * base;
    base = base * 2;
  }
  return decimal;
}

// objetivo: gerar o filho
int *criar_filho(int *bin_pai, int *bin_mae){
  int *filho = (int*) malloc(32 * sizeof(int));
  for (int i = 31; i >= 0; i--){
    int gene = rand() % 2;
    // se o gene for impar, vai ser da mae
    if(gene == 1){
      filho[i] = bin_mae[i];
    }
    else{ // caso contrario, do pai
      filho[i] = bin_pai[i];
    }
  }
  return filho;
}

// objetivo: trocar o binario
int negado(int bit){
  if (bit == 0){
    return 1;
  }
  return 0;
}

// objetivo: incluir o fator mutação
void filho_mutado(int *filho, double mutacao){
  int taxa = mutacao * 100;
  for (int i = 31; i >=0; i--){
    int chance = rand() % 100;
    if (chance < taxa){
      filho[i] = negado(filho[i]);
    }
  }
}

// objetivo: escolher os pais ate eles terem filhos suficientes
void melhores(CANDIDATO *geracao, int tam, double mutacao){
  // pegando metade do vetor
  int metade;
  if (tam % 2 == 0){
    metade = tam/2;
  }
  else{
    metade = (tam/2) + 1;
  }
  
  // completando a outra metade do vetor com os filhos
  for (int i = 0; i < tam - metade; i++){
    int pai = rand() % metade;
    // garantindo que os pais sao diferentes:
    int mae;
    do{
      mae = rand() % metade;
    }while (pai == mae);

    // colocando os pais em forma binaria
    int *pai_bin = (int*) malloc (32 * sizeof(int));
    pai_bin = dec_bin(geracao[pai].numero);
    int *mae_bin = (int*) malloc (32 * sizeof(int));
    mae_bin = dec_bin(geracao[mae].numero);

    // criando o filho
    int *filho = criar_filho(pai_bin, mae_bin);
    filho_mutado(filho, mutacao);
    
    // transformar em decimal e colocando na struct
    geracao[metade + i].numero = bin_dec(filho);
    geracao[metade + i].fitness = 0;
  }
}

// objetivo: verificar se algum numero resolveu a equação:
bool candidato_ideal(CANDIDATO *geracao, int tam){
  for (int i = 0; i < tam; i++){
    if (geracao[i].fitness == 0){
      return true;
    }
  }
  return false;
}

// objetivo: imprimir a struct
void imprimir_vetor(CANDIDATO *geracao, int tam){
  for (int i = 0; i < tam; i++){
    printf("Valor: %d  ", geracao[i].numero);
    printf("Fitness: %d\n", geracao[i].fitness);
  }
}