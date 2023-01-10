#include <stdio.h>
#include <stdlib.h>
#include "Pathfinder.h"
/*
5 1 
1 2 300
1 3 500
1 4 390
1 5 390
2 3 350
2 4 380
2 5 490
3 4 400
3 5 360
4 5 350
*/
int main(){
    // parte da leitura
    int qtt_cidades, cidade_inicial;
    scanf("%d %d%*c", &qtt_cidades,&cidade_inicial);
    cidade_inicial-=1;//converte para a medida do programa
    
    //cria o mapa
    DM_MATRIX *map = matrixconfig_create(qtt_cidades,qtt_cidades,-1);//cria uma struct de matriz cheia de -1 (sem conexoes)
    int x,y;
    ITEM distxy;
    for(int i=0;i<(qtt_cidades*qtt_cidades-qtt_cidades);i++){
        scanf("%d %d %f%*c",&x,&y,&distxy);
        matrixconfig_set(map,x-1,y-1,distxy);
        matrixconfig_set(map,y-1,x-1,distxy);
    }
    matrixconfig_cleardiagonal(map);
    
    //cria a rede e o walker
    WEB *web = web_create(map,cidade_inicial);
    WALKER *walker = walker_create(qtt_cidades,cidade_inicial);
    walker_run(walker,web);
    walker_printruncodes(walker,web);
    return 0;
}