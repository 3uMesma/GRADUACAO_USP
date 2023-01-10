#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
struct tree{
    TREE *esq;
    TREE *dir;
    DATA *data;
    int balance;
};

TREE *tree_create(DATA *ref){
    TREE *sn = malloc(sizeof(TREE));
    sn->esq=NULL;
    sn->dir=NULL;
    sn->data=ref;
    return sn;
}
void tree_data_remove_function(DATA **remove){//Função de remover que conecta o item.h e o tree.h
    item_free(remove);
}
void tree_free(TREE **remove,bool remove_items){
    if(*remove==NULL){return;}
    tree_free(&((*remove)->esq),remove_items);
    tree_free(&((*remove)->dir),remove_items);
    if(remove_items){
        tree_data_remove_function(&((*remove)->data));//chama a função para remover o item também
    }
    free(*remove);
    *remove=NULL;
}


int data_compara(DATA *a,DATA *b){//Faz a adaptação do tree.h para funcionar com o item.h
    // if(*a>*b){
    //     return 1;
    // }else if(*a<*b){
    //     return -1;
    // }else{
    //     return 0;
    // }
    return item_compare(a,b);//chama a função do item.h para poder ser adaptável a outros tipos de dados caso seja necessário
}
int data_get(DATA *data){//Faz a adaptação do tree.h para funcionar com o item.h
    return item_get_valor(data);
}



TREE *tree_rotate_DD(TREE *rotacionar){
    TREE *nova_arvore = rotacionar->esq;
    rotacionar->esq = nova_arvore->dir;
    nova_arvore->dir = rotacionar;
    return nova_arvore;
}
TREE *tree_rotate_EE(TREE *rotacionar){
    TREE *nova_arvore = rotacionar->dir;
    rotacionar->dir = nova_arvore->esq;
    nova_arvore->esq = rotacionar;
    return nova_arvore;
}
TREE *tree_rotate_DE(TREE *rotacionar){
    rotacionar->dir = tree_rotate_DD(rotacionar->dir);
    rotacionar = tree_rotate_EE(rotacionar);
    return rotacionar;
}
TREE *tree_rotate_ED(TREE *rotacionar){
    rotacionar->esq = tree_rotate_EE(rotacionar->esq);
    rotacionar = tree_rotate_DD(rotacionar);
    return rotacionar;
}




void tree_try_rotate(TREE **t, bool is_esq, bool *flag){//Aplica uma rotação na árvore de acordo com o fator de balanceamento do nó 
    if(*flag==false){return;}
    if(is_esq){//caso o nó que vá adicionar fique na esquerda
        switch((*t)->balance){
            case -1:
                (*t)->balance=0;
                *flag=false;
                break;
            case 0: (*t)->balance=1;*flag=true;break;//liga a flag para rotacionar o pai
            case 1:
                if((*t)->esq->balance==1){
                    (*t) = tree_rotate_DD((*t));
                    (*t)->dir->balance=0;
                    (*t)->balance=0;
                    *flag=false;
                    break;
                }else{//Se não, (*t)->dir->balance==-1
                    (*t) = tree_rotate_ED((*t));
                    switch((*t)->balance){
                        case -1:
                            (*t)->esq->balance=1;
                            (*t)->dir->balance=0;
                            break;
                        case 0:
                            (*t)->esq->balance=0;
                            (*t)->dir->balance=0;
                            break;
                        case 1:
                            (*t)->esq->balance=0;
                            (*t)->dir->balance=-1;
                            break;
                        default: break;
                    }
                    (*t)->balance=0;
                    *flag=false;
                    break;
                }
        }
    }else{//caso o nó que vá adicionar fique na direita
        switch((*t)->balance){
            case 1:
                (*t)->balance=0;
                *flag=false;
                break;
            case 0: (*t)->balance=-1;*flag=true;break;
            case -1:
                if((*t)->dir->balance==-1){
                    (*t) = tree_rotate_EE((*t));
                    (*t)->esq->balance=0;
                    (*t)->balance=0;
                    *flag=false;
                    break;
                }else{//Se não, (*t)->dir->balance==-1
                    (*t) = tree_rotate_DE((*t));
                    switch((*t)->balance){
                        case 1:
                            (*t)->dir->balance=-1;
                            (*t)->esq->balance=0;
                            break;
                        case 0:
                            (*t)->dir->balance=0;
                            (*t)->esq->balance=0;
                            break;
                        case -1:
                            (*t)->dir->balance=0;
                            (*t)->esq->balance=1;
                            break;
                        default: break;
                    }
                    (*t)->balance=0;
                    *flag=false;
                    break;
                }
        }
    }

}

bool tree_inserir_rec(TREE **sn,DATA *toadd, bool *flag){
    
    if(*sn==NULL){*sn = tree_create(toadd);return false;}
    if(*flag){
        
        switch(data_compara((*sn)->data,toadd)){
            case 1://O valor é menor que o nó atual (adiciona na esquerda), tenta rotacionar
                if(!tree_inserir_rec(&((*sn)->esq),toadd,flag)){
                    tree_try_rotate(sn,true,flag);//aplica uma rotação para a esquerda (a depender da flag que diz se o pai será rotacionado)
                }
                break;
            case 0:
                return true;//O valor já existe
            case -1://O valor é maior que o nó atual (adiciona na direita), tenta rotacionar
                if(!tree_inserir_rec(&((*sn)->dir),toadd,flag)){
                    tree_try_rotate(sn,false,flag);//aplica uma rotação para a direita (a depender da flag que diz se o pai será rotacionado)
                }
                break;
            default:
                break;
        }
    }
    
}
bool tree_inserir(TREE **t,DATA *toadd){
    bool flag = true;
    return tree_inserir_rec(t,toadd,&flag);;
}



TREE *tree_remove_balancear(TREE *t, bool is_esq, bool *flag){//Remove um nó e aplica as rotações para balancear
    if(is_esq){
        switch(t->balance){
            case 1:
                t->balance=0;break;
            case 0:
                t->balance=-1;*flag=false;break;
            case -1:
                if(t->dir->balance<=0){
                    t = tree_rotate_EE(t);
                    if(t->balance==0){
                        t->esq->balance=-1;
                        t->balance=1;
                        *flag=0;
                    }else{
                        t->esq->balance=0;
                        t->balance=0;
                    }
                }else{
                    t = tree_rotate_DE(t);
                    if(t->balance==1){
                        t->esq->balance=0;
                        t->dir->balance=-1;
                    }else if(t->balance==-1){
                        t->esq->balance=1;
                        t->dir->balance=0;
                    }else{
                        t->esq->balance=0;
                        t->dir->balance=0;
                    }
                    t->balance=0;
                }
        }
    }else{
        switch(t->balance){
            case -1:
                t->balance=0;break;
            case 0:
                t->balance=1;*flag=false;break;
            case 1:
                if(t->esq->balance>=0){
                    t = tree_rotate_DD(t);
                    if(t->balance==0){
                        t->dir->balance=1;
                        t->balance=-1;
                        *flag=0;
                    }else{
                        t->dir->balance=0;
                        t->balance=0;
                    }
                }else{
                    t = tree_rotate_ED(t);
                    if(t->balance==1){
                        t->esq->balance=0;
                        t->dir->balance=-1;
                    }else if(t->balance==-1){
                        t->esq->balance=1;
                        t->dir->balance=0;
                    }else{
                        t->esq->balance=0;
                        t->dir->balance=0;
                    }
                    t->balance=0;
                }
        }
    }
    return t;
}
TREE *tree_remove_busca(TREE *a, TREE *key, bool *flag){//troca as chaves [de A com o key] para o caso de estar querendo remover a raiz. Caso não seja a raiz, busca o maior nó da subárvore e faz essa troca, com balanceamento em A se precisar
    TREE *aux;
    if(a->dir!=NULL){
        a->dir = tree_remove_busca(a->dir,key,flag);
        if(flag){
            a=tree_remove_balancear(a,false,flag);
        }
    }else{
        key->data = a->data;
        aux = a;
        a = a->esq;
        free(aux);
        *flag = true;
    }
}
TREE *tree_remove_nonflag(TREE *raiz, DATA *toremove, bool *flag){
    //Função principal de remover: compara os itens e vai fazendo uma recursão até chegar no nó a ser removido (case 0)
    //Quando acha o nó a ser removido, apaga o nó, faz uma ligação com o tree_remove_busca 
    //  (troca as chaves para o caso de estar querendo remover a raiz. Caso não seja a raiz, busca o maior nó da subárvore e faz essa troca, com balanceamento se precisar)
    TREE *aux;
    if(raiz==NULL){*flag=false;}else{
    //printf("meu raiz: %d compara com %d\n",*(raiz->data),*toremove);
    switch(data_compara(toremove,raiz->data)){
        case -1://É menor que o que está procurando
            raiz->esq = tree_remove_nonflag(raiz->esq,toremove,flag);
            if(flag){raiz = tree_remove_balancear(raiz,true,flag);}
            break;
        case 1://É maior que o que está procurando
            raiz->dir = tree_remove_nonflag(raiz->dir,toremove,flag);
            if(flag){raiz = tree_remove_balancear(raiz,false,flag);}
            break;
        case 0://É o que precisa remover
            if(raiz->dir==NULL){
                aux=raiz;
                raiz=raiz->esq;
                free(aux);
                *flag=true;
            }else if(raiz->esq==NULL){
                aux=raiz;
                raiz=raiz->dir;
                free(aux);
                *flag=true;
            }else{
                raiz->esq = tree_remove_busca(raiz->esq,raiz,flag);
                if(flag){raiz = tree_remove_balancear(raiz,true,flag);}
            }
            break;
    }}
    return raiz;
}
void tree_remove(TREE **raiz,DATA *toremove){
    bool flag = false;
    *raiz = tree_remove_nonflag(*raiz,toremove,&flag);
}


bool tree_contains(TREE *raiz,DATA *item){
    if(raiz==NULL){return false;}
    switch(data_compara(item,raiz->data)){
        case -1: return tree_contains(raiz->esq,item);break;
        case 0: return true;
        case 1: return tree_contains(raiz->dir,item);break;
    }
}




void tree_print(TREE *sn){
    if(sn!=NULL){
        printf("%d",data_get(sn->data));
        if(sn->esq==NULL && sn->dir==NULL){return;}
        printf("(");
        if(sn->esq==NULL){printf("_");}else{tree_print(sn->esq);}
        printf(",");
        if(sn->dir==NULL){printf("_");}else{tree_print(sn->dir);}
        printf(")");
    }
}
void tree_print_nonspace(TREE *sn){
    if(sn!=NULL){
        printf(" %d ",data_get(sn->data));
        if(sn->esq==NULL && sn->dir==NULL){return;}
        if(sn->esq!=NULL){tree_print_nonspace(sn->esq);}
        if(sn->dir!=NULL){tree_print_nonspace(sn->dir);}
    }
}


void tree_copy_rec(TREE *t,TREE **toadd){
    if(t==NULL){return;}
    if(t->esq!=NULL){tree_copy_rec(t->esq,toadd);}
    if(t->dir!=NULL){tree_copy_rec(t->dir,toadd);}
    tree_inserir(toadd,item_copy(t->data));
}
TREE *tree_copy(TREE *t){
    TREE *copy = NULL;
    tree_copy_rec(t,&copy);
    return copy;
}
TREE *tree_merge(TREE *a, TREE *b){
    TREE *c = NULL;
    tree_copy_rec(a,&c);
    tree_copy_rec(b,&c);
    return c;
}

void tree_copy_rec_ifcontains(TREE *t,TREE **toadd,TREE *if_is_here){
    if(t==NULL){return;}
    if(t->esq!=NULL){tree_copy_rec_ifcontains(t->esq,toadd,if_is_here);}
    if(t->dir!=NULL){tree_copy_rec_ifcontains(t->dir,toadd,if_is_here);}
    if(tree_contains(if_is_here,t->data)){tree_inserir(toadd,t->data);}
}
TREE *tree_union(TREE *a, TREE *b){
    TREE *c = NULL;
    tree_copy_rec_ifcontains(a,&c,b);
    return c;
}