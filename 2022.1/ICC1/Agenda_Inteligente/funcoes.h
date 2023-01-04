#ifndef FUNCOES_H
#define FUNCOES_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #define Qpreferencia 3
    char gostosNomes[Qpreferencia][20] = {"RPG","FPS","jogos de cartas"};
    int i,a,r;

    typedef struct{
        int dia;int mes;int ano;
    }data;

    typedef struct{
        char nome[100];
        data nascimento;
        char cidade[100];
        char UF[3];
        float gostos[Qpreferencia];
        int grupo;//Se o grupo for igual a -2, a pessoa é tratada como excluida (não aparece nas funções)
    }aluno;

    aluno *CadastrarManualmente(aluno *alunos,int *qalunos);
    void editar_registro(aluno *alunos);
    void excluir(aluno *alunos, int qalunos);
    void busca(aluno *alunos, int q_alunos);
    void BubbleSort(aluno *alunos,int qalunos,int opt);
    void CriarGrupos(aluno *alunos,int qalunos,float limiar);
    void printaAllAlunos(aluno *alunos,int qalunos);


#endif