#include <stdio.h>
#include <stdlib.h>
#include "Pathfinder.h"
#include <time.h>



int main(){
    srand(time(NULL));
    printf("iniciouz\n");
    //Nota: caso queira testar os casos de teste, retire os comentários, remova "matrixconfig_randomize" e coloque "matrixconfig_cleardiagonal"
    /*char nome_arquivo[50]="casosteste/3.in";//Melhor caminho: [2 6 11 3 5 7 9 10 0 1 4 ] = 761.000000
    FILE *arq;
    int qtt_cidades, cidade_inicial;

    printf("Digite o nome do arquivo: ");
    //scanf("%s", nome_arquivo);
    arq = fopen(nome_arquivo, "r");

    // parte da leitura
    fscanf(arq, "%d", &qtt_cidades);
    fscanf(arq, "%d", &cidade_inicial);
    cidade_inicial-=1;//converte para a medida do programa*/
    
    
    int qtt_cidades = 100;int cidade_inicial = 0;
    //printf("distancemap\n");
    DM_MATRIX *map = matrixconfig_create(qtt_cidades,qtt_cidades,-1);//cria uma struct de matriz cheia de -1 (sem conexoes)
    int x,y;
    ITEM distxy;
    /*while(feof(arq)==0){
        fscanf(arq, "%d %d %f",&x,&y,&distxy);
        matrixconfig_set(map,x-1,y-1,distxy);
        matrixconfig_set(map,y-1,x-1,distxy);
    }
    fclose(arq);*/
    matrixconfig_print(map);printf("\n\n\n");
    
    matrixconfig_randomize(map);
    matrixconfig_cleardiagonal(map);

    matrixconfig_print(map);
    WEB *web = web_create(map,cidade_inicial);
    printf("cidade inicial: %d\n",cidade_inicial);
    printf("\n\nmetodo alternativo monte carlo:\n");
    WALKER *walker2 = walker_run2(web,500,20);
    walker_printbest(walker2);
    printf("Caminho encontrado pelo metodo alternativo: ");walker_printruncodes(walker2,web);printf("\n\n\n");


    
    /*printf("\n\nmetodo de forca bruta:\n");
    if(qtt_cidades>11){return 0;}//prevenção caso você coloque qtt_cidades>12 e ative esse código
    WALKER *walker = walker_create(qtt_cidades,cidade_inicial);
    walker_run(walker,web);
    walker_printbest(walker);
    printf("runcodes: ");walker_printruncodes(walker,web);printf("\n\n\n");*/


    
    return 0;
}