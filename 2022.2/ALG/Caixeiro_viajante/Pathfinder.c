#include <stdio.h>
#include <stdlib.h>
#include "Pathfinder.h"


struct walker{
    ITEM distancia_atual;//auxiliar que serve só para guarda a distância atual a cada ciclo
    ITEM bestdistance;//guarda a melhor distância
    int lenpath;//guarda o tamanho do caminho
    int *path_atual;//guarda o caminho atual
    int *bestpath;//guarda o melhor caminho

};
WALKER *walker_create(int lenpath,int cidadeinicial){
    lenpath-=1;
    WALKER *w = malloc(sizeof(WALKER));
    w->bestpath = malloc(sizeof(int)*lenpath);
    w->path_atual = calloc(sizeof(int),lenpath);
    w->lenpath=lenpath;
    w->bestdistance=__FLT_MAX__;int marcador=0;
    for(int i=0;i<lenpath+1;i++){
        if(i!=cidadeinicial){w->path_atual[marcador]=i;marcador++;}
    }
    return w;
}
void walker_reset(WALKER *w){
    w->bestdistance=__FLT_MAX__;
    for(int i=0;i<w->lenpath;i++){
        w->path_atual[i]=i;
    }
}

int array_contains(int *array, int item, int len){
    for(int i=0;i<len;i++){
        if(array[i]==item && array[i]!=-1){return 1;}
    }
    return 0;
}
void walker_setpath(WALKER *w, int *newpath){
    array_copyto(w->path_atual,newpath,w->lenpath);
}
int *walker_getpreset(int *presetpath,int len,int initialnode){
    int *preseted = malloc(sizeof(int)*len);
    int another_count=0;
    for(int i=0;i<len;i++){
        if(presetpath[i]!=-1){
            preseted[i]=presetpath[i];
        }else{
            while(array_contains(presetpath,another_count,len) || another_count==initialnode){another_count++;}
            preseted[i]=another_count;
            another_count++;
        }
    }
    return preseted;
}
void walker_free(WALKER **w){
    if(w==NULL){return;}
    free((*w)->bestpath);
    free((*w));
    (*w)=NULL;
}

ITEM walker_getdistance(WALKER *w){
    return w->distancia_atual;
}
ITEM walker_getbestdistance(WALKER *w){
    return w->bestdistance;
}
int walker_getlenpath(WALKER *w){
    return w->lenpath;
}
int *walker_getpath(WALKER *w){
    return w->path_atual;
}
int *walker_getbestpath(WALKER *w){
    return w->bestpath;
}


void walker_setbest(WALKER *w){
    w->bestdistance = w->distancia_atual;
    for(int i=0;i<w->lenpath;i++){
        w->bestpath[i]=w->path_atual[i];
    }
}
void walker_setbestif(WALKER *w){//seta caso seja a melhor distância
    //printf("comparing: %f < %f\n",walker_getdistance(w),walker_getbestdistance(w));
    if(walker_getdistance(w)<walker_getbestdistance(w)){
        //printf("    e o melhorcaminho :)\n");
        walker_setbest(w);
    }
}
void walker_printpath(WALKER *w){
    printf("[");
    for(int i=0;i<w->lenpath;i++){
        printf("%d ",walker_getpath(w)[i]);
    }
    printf("]");
}



void swap(int *a,int *b){
    int copy = *a;
    *a = *b;
    *b = copy;
}
void walker_trypath(WALKER *walker,WEB *web){
    web_reset(web);//reseta a rede (volta a cidade inicial)
    walker->distancia_atual=0;
    if(web_trypath(web,walker_getpath(walker),walker_getlenpath(walker),&(walker->distancia_atual))){
        if(web_trymove(web,web_initialnodeid(web),&(walker->distancia_atual))){
            /*if(walker->distancia_atual==1750.00){//caso1
                walker_printpath(walker);printf("==1750.00\n");
            }*/
            /*if(walker->distancia_atual==543.00){//caso2
                walker_printpath(walker);printf("==543.00\n");
            }*/
            /*if(walker->distancia_atual==761.00){//caso 3
                walker_printpath(walker);printf("==761.00\n");
            }*/
            /*if(walker->distancia_atual==929.00){//caso 4
                walker_printpath(walker);printf("==929.00\n");
            }*/

            walker_setbestif(walker);
            return;
        }
        return;
    }
    return;//o caminho deu ruim, então ele só retorna
    
}

void walker_trypathPRINT(WALKER *walker,WEB *web){
    walker->distancia_atual=0;
    printf("printando passo a passo do path: ");walker_printpath(walker);printf("\n");
    if(web_trypathPRINT(web,walker_getpath(walker),walker_getlenpath(walker),&(walker->distancia_atual))){
        if(web_trymovePRINT(web,web_initialnodeid(web),&(walker->distancia_atual))){
            walker_setbestif(walker);
            web_reset(web);//reseta a rede (volta a cidade inicial)
            return;
        }
        printf("erro1\n");
        return;
    }
    printf("erro2\n");
    return;//o caminho deu ruim, então ele só retorna
}





void heapPermutation(WEB *web,int size, WALKER *walker)
{
    if (size == 1) {

        walker_trypath(walker,web);
    }
    for (int i = 0; i < size; i++) {
        
        heapPermutation(web,size - 1,walker);
        if (size % 2 == 1){
            swap(&(walker_getpath(walker)[0]), &(walker_getpath(walker)[size - 1]));
        }
        else{
            swap(&(walker_getpath(walker)[i]), &(walker_getpath(walker)[size - 1]));
        }
    }
}

void walker_run(WALKER *walker, WEB *web){
    heapPermutation(web,web_getlennodes(web)-1,walker);
}
void walker_printbest(WALKER *w){
    printf("Melhor caminho: [");
    for(int i=0;i<walker_getlenpath(w);i++){
        printf("%d ",(walker_getbestpath(w))[i]);
    }
    printf("] = %f\n",walker_getbestdistance(w));
}

void walker_printruncodes(WALKER *w,WEB *web){
    printf("%d ",web_initialnodeid(web)+1);
    for(int i=0;i<w->lenpath;i++){
        printf("%d ",w->bestpath[i]+1);
    }
    printf("%d",web_initialnodeid(web)+1);
    web_reset(web);
}











void array_shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void array_copyto(int *copyto,int *copyfrom,int len){
    for(int i=0;i<len;i++){
        copyto[i]=copyfrom[i];
    }
}
void array_print(float *array,int len){
    for(int i=0;i<len;i++){
        printf("%.2f ",array[i]);
    }
}
void array_printint(int *array,int len){
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
}
int array_minN(float *array,int len){
    int idxmin=0;
    for(int i=1;i<len;i++){
        if((array[idxmin]>array[i] && array[i]!=-1)||array[idxmin]==-1){idxmin=i;}
    }
    return idxmin;
}
WALKER *walker_run2(WEB *web, int q_walkers,int q_shuffles){
    int q_nodes = web_getlennodes(web);
    //printf("web inicial: %d\n",web_initialnodeid(web));
    WALKER **walkers = malloc(sizeof(WALKER*)*q_walkers);for(int w=0;w<q_walkers;w++){walkers[w]=walker_create(q_nodes,web_initialnodeid(web));}
    
    int *finded_path = malloc(sizeof(int)*(q_nodes-1));for(int n=0;n<q_nodes-1;n++){finded_path[n]=-1;}
    //finded_path[0]=web_initialnodeid(web);
    ITEM *heuristic_count = malloc(sizeof(ITEM*)*(q_nodes));
    int *divisor_count = malloc(sizeof(int)*q_nodes);
    int *preset = malloc(sizeof(int)*(q_nodes-1));

    for(int d=0;d<q_nodes-1;d++){
        preset = walker_getpreset(finded_path,q_nodes-1,web_initialnodeid(web));
        //printf("finded_path: ");array_printint(finded_path,q_nodes-1);printf("\n");
        //printf("    -->preset feito: ");array_printint(preset,q_nodes-1);printf("\n");
        for(int i=0;i<q_nodes;i++){//reseta o contador de distancias
            heuristic_count[i]=-1;
            divisor_count[i]=0;
        }
        for(int w=0;w<q_walkers;w++){//roda todos os walkers
            walker_reset(walkers[w]);
            array_copyto(walkers[w]->path_atual, preset , q_nodes);//coloca com o preset
            for(int s=0;s<q_shuffles;s++){//faz cada um "q_shuffles" vezes
                array_shuffle(walkers[w]->path_atual+d,q_nodes-d-1);
                walker_trypath(walkers[w],web);
            }
            //printf("    walker [%d]: ",w);walker_printbest(walkers[w]);
            heuristic_count[ walkers[w]->bestpath[d] ] += walkers[w]->bestdistance;
            divisor_count[ walkers[w]->bestpath[d] ] +=1;
        }
        for(int i=0;i<q_nodes;i++){//reseta o contador de distancias
            if(divisor_count[i]==0){continue;}
            heuristic_count[i]/=divisor_count[i];
        }
        //printf("Array final da geracao %d: ",d);array_print(heuristic_count,q_nodes);
        int max = array_minN(heuristic_count,q_nodes);
        //printf("tentando salvar: %d\n",max);
        if(array_contains(finded_path,max,q_nodes-1)){d--;continue;}//trava de segurança
        //printf("\nsalvo como menor: %d\n\n\n",max);
        finded_path[d] = max;
    }
    
    //printf("finalizado\n");
    //printf("Path achado: [");array_printint(finded_path,q_nodes);printf("]\n");
    WALKER *w = walker_create(q_nodes,web_initialnodeid(web));
    array_copyto(w->bestpath,finded_path,q_nodes);
    array_copyto(w->path_atual,finded_path,q_nodes);
    walker_trypath(w,web);
    free(preset);
    free(heuristic_count);
    free(finded_path);
    for(int w=0;w<q_walkers;w++){walker_free(&walkers[w]);}
    free(walkers);
    return w;
}