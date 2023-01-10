#include <stdio.h>
#include <stdlib.h>
#include "Connector.h"
struct line{
    ITEM distance;
    NODE *conn;
};
struct node{
    int id;
    int len_conns;
    LINE **conns;
};
NODE *node_create(int id){
    NODE *n = malloc(sizeof(NODE));
    n->id = id;
    n->len_conns=0;
    n->conns = malloc(sizeof(LINE*)*1);
    return n;
}
LINE *line_create(NODE *c, ITEM d){
    LINE *l = malloc(sizeof(LINE));
    l->distance=d;
    l->conn=c;
    return l;
}
bool line_free(LINE **l){
    if(l==NULL){return false;}
    free(*l);
}
bool node_free(NODE **n){
    if(n==NULL){return false;}
    for(int i=0;i<(*n)->len_conns;i++){
        line_free(&((*n)->conns[i]));
        //limpa todas as ruas conectadas a ele (a rua só é útil a um nó, então não faz sentido não desalocar junto)
    }
    free(*n);
    *n=NULL;
}




bool node_addline(NODE *n, LINE *l){
    (n->len_conns)++;
    n->conns = (LINE**)realloc(n->conns,sizeof(LINE*)*(n->len_conns));//realoca o tamanho de lines no nó
    if(n->conns==NULL){return false;}
    n->conns[n->len_conns-1] = l;
    return true;
}
bool node_create_connection(NODE *a, NODE *b, ITEM distance){//aloca uma rua de ida (não cria uma rua de volta, deixa isso a cargo da matriz de distâncias)
    if(a==NULL || b==NULL){return false;}
    if(!node_addline(a,line_create(b,distance))){return false;}
    return true;
}




struct web{
    NODE *you;    //marca a posição que você está na rede
    NODE *reset;
    NODE **nodes; //guarda todos os nós da rede
    int len_nodes;
};
WEB *web_create(DM_MATRIX *d, int initial_id){
    assert(matrixconfig_getN(d)==matrixconfig_getM(d));//confere para saber se vc n é burro e fez matrizes com dimensões diferentes
    WEB *w = malloc(sizeof(WEB));
    w->nodes = malloc(sizeof(NODE)*matrixconfig_getN(d));        //cria um espaço para n ponteiros de nós
    w->len_nodes=matrixconfig_getN(d);
    for(int i=0;i<w->len_nodes;i++){
        w->nodes[i] = node_create(i);         //cria todos os nós (nenhum está conectado a nada)
    }
    for(int x=0;x<w->len_nodes;x++){
        for(int y=0;y<w->len_nodes;y++){
            node_create_connection(w->nodes[x],w->nodes[y],matrixconfig_get(d,x,y));
        }
    }
    web_setresetbyid(w,initial_id);
    web_goto(w,w->reset);
    return w;
}
void web_reset(WEB *w){
    w->you=w->reset;
}
void web_setresetbyid(WEB *w,int id){
    w->reset = web_findnodebyid(w,id);
}
int web_getlennodes(WEB *w){
    return w->len_nodes;
}
void web_showconnections(WEB *w){
    printf("mostrando conexoes:\n");
    for(int i=0;i<w->len_nodes;i++){
        printf("    nó {%d}:\n",i);
        for(int c=0;c<w->nodes[i]->len_conns;c++){
            printf("        -- utilizando o caminho [%d] de distancia %.2f, chega-se ao nó {%d}\n",
                    c,
                    w->nodes[i]->conns[c]->distance,
                    w->nodes[i]->conns[c]->conn->id
            );
        }
    }
}
NODE *web_findnodebyid(WEB *w,int id){
    for(int i=0;i<w->len_nodes;i++){
        if(w->nodes[i]->id==id){
            return w->nodes[i];
        }
    }
    return NULL;
}
void *web_setmebyid(WEB *w,int id){
    w->you = web_findnodebyid(w,id);
}
NODE *web_getme(WEB *w){
    return w->you;
}
int web_getmeid(WEB *web){
    return web->you->id;
}
void web_goto(WEB *w,NODE *go){//move instaneamente para uma posição
    w->you=go;
}
int web_initialnodeid(WEB *w){
    return w->reset->id;
}
bool web_trymove(WEB *w,int gotoline,ITEM *distance_accumulator){
    
    LINE *l = w->you->conns[gotoline];
    if(l->distance<0){return false;}//Se a distância do caminho for negativa, por padrão retorna falso (caminho bloqueado)
    (*distance_accumulator)+=l->distance;
    /*printf("            usando o caminho %d [distancia = %.2f] foi da cidade %d ate a cidade %d (%f)\n",
            gotoline,
            w->you->conns[gotoline]->distance,
            w->you->id,
            w->you->conns[gotoline]->conn->id,
            *distance_accumulator
    );*/
    w->you=l->conn;
    l=NULL;
    return true;
}
bool web_trymovePRINT(WEB *w,int gotoline,ITEM *distance_accumulator){
    LINE *l = w->you->conns[gotoline];
    if(l->distance<0){return false;}//Se a distância do caminho for negativa, por padrão retorna falso (caminho bloqueado)
    (*distance_accumulator)+=l->distance;
    printf("            usando o caminho %d [distancia = %.2f] foi da cidade %d ate a cidade %d (%f)\n",
            gotoline,
            w->you->conns[gotoline]->distance,
            w->you->id,
            w->you->conns[gotoline]->conn->id,
            *distance_accumulator
    );
    w->you=l->conn;
    l=NULL;
    return true;
}
bool web_trypath(WEB *w,int *path,int len_path,ITEM *distance_accumulator){
    for(int i=0;i<len_path;i++){
        if(!web_trymove(w,path[i],distance_accumulator)){return false;}//se algum travar, já retorna falso (tentou ir por um caminho bloqueado)
    }
    return true;
}
bool web_trypathPRINT(WEB *w,int *path,int len_path,ITEM *distance_accumulator){
    for(int i=0;i<len_path;i++){
        if(!web_trymovePRINT(w,path[i],distance_accumulator)){return false;}//se algum travar, já retorna falso (tentou ir por um caminho bloqueado)
    }
    return true;
}