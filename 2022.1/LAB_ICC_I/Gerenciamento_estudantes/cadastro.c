#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gerenciamento_estudante{
  int NUSP;
  char nome[200];
  char curso[100];
  int idade;
  }alunos_t;

void imprimir(int n, alunos_t *alunos){
  printf("Nome: %s\n", alunos[n].nome);
  printf("Curso: %s\n", alunos[n].curso);
  printf("N USP: %d\n", alunos[n].NUSP);
  printf("IDADE: %d\n", alunos[n].idade);
  printf("\n");
}

int main(void) {
  int qtt_alunos = 1;
  alunos_t *alunos = (alunos_t*) malloc (qtt_alunos * sizeof(alunos_t));

  // leitura de dados dos alunos
  while (1) {
    scanf("%d%*c", &alunos[qtt_alunos - 1].NUSP);    
    if (alunos[qtt_alunos - 1].NUSP == -1) break;
    scanf("%200[^\n]%*c", alunos[qtt_alunos - 1].nome); 
    scanf("%100[^\n]%*c", alunos[qtt_alunos - 1].curso);
    scanf("%d%*c", &alunos[qtt_alunos - 1].idade);
    qtt_alunos++;
    alunos = (alunos_t*) realloc (alunos, qtt_alunos * sizeof(alunos_t));
    }

  // leitura dos comandos
  int opcao;
  do{
    scanf("%d%*c", &opcao);
    //printf("Opcao: %d\n", opcao);
    if (opcao == - 1)break;
    int NUSP_desejado;
    char curso_desejado[100];
    switch(opcao){
      case 1:
        scanf("%d%*c", &NUSP_desejado);
        for (int i = 0; i < qtt_alunos; i++){
          if (alunos[i].NUSP == NUSP_desejado){
            imprimir(i, alunos);
          }
        }
      break;

      case 2:
        scanf("%100[^\n]%*c", curso_desejado);
        for (int i = 0; i < qtt_alunos; i++){
          if (strcmp(alunos[i].curso, curso_desejado) == 0){
            imprimir(i, alunos);
          }
        }
      break;

      case 3:
        for (int i = 0; i < qtt_alunos - 1; i++){
          imprimir(i, alunos);
        }
      }
    }
    while(opcao != -1);

  free(alunos);
  
  return 0;
}
