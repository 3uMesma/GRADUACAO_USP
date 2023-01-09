#include "ABB.h"
#include "item.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// usamdo a struct disponível no run codes:
typedef struct No NO;
struct No {
  ITEM *item;
  NO *esq;
  NO *dir;
};

struct abb {
  NO *raiz;
  int profundidade;
};

// função criar arvore:
ABB *abb_criar(void) {
  ABB *a = (ABB *)malloc(sizeof(ABB));
  a->raiz = NULL;
  return a;
}

// função pra inserir na arvore:
bool abb_inserir(ABB *T, ITEM *item) {
  // criando um nó temporário:
  NO *no_temp = (NO*) malloc(sizeof(NO));
  NO *atual;
  NO *pai;

  no_temp -> item = item;
  no_temp -> esq = NULL;
  no_temp -> dir = NULL;

  //se a árvore estiver vazia:
  if(T -> raiz == NULL) {
    T -> raiz = no_temp;
  } else {
    atual = T -> raiz;
    pai = NULL;

    while(1) {                
      pai = atual;
      elem novo = get_valor(item);
      elem info = get_valor(pai -> item);
      //vá para a esquerda da árvore
      if(novo < info) {
        atual = atual -> esq;                
        //insira à esquerda
        if(atual == NULL) {
          pai -> esq = no_temp;
          return true;
        }
      }//vá para a direita da árvore:
      else {
        atual = atual -> dir;
        //insira à direita
        if(atual == NULL) {
          pai -> dir = no_temp;
          return true;
        }
      }
    }            
  }
  return true;
}        

// funções para imprimir arvore:
void imprime(NO *raiz) {
	if(raiz != NULL) {
		printf("%d(", get_valor(raiz->item));
		imprime(raiz->esq);
		printf(",");
		imprime(raiz->dir);
		printf(")");
	} else {
		printf("_");
	}
}
void abb_imprimir(ABB *A) {
	imprime(A->raiz);
	printf("\n");
}

// função para apagar toda a arvore:
void abb_apagar (ABB **T){
  // remover a raiz:
  elem valor_raiz = get_valor((*T)-> raiz -> item);
  abb_remover(*T, valor_raiz);
  free(*T);
  *T = NULL;
}

NO *busca_pai(NO *raiz, int chave) {
  if(raiz == NULL)
    return NULL;
  
  if(raiz->esq != NULL && get_valor(raiz->esq->item) == chave)
    return raiz;
  
  if(raiz->dir != NULL && get_valor(raiz->dir->item) == chave)
    return raiz;
  
  NO *p = busca_pai(raiz->esq, chave);
  if(p == NULL)
    p = busca_pai(raiz->dir, chave);
  
  return p;
}

NO *buscar_pai(ABB *T, int chave) {
  return busca_pai(T -> raiz, chave);
}

// função para remover apenas um item:
bool abb_remover(ABB *T, int chave){
  NO *pai, *p;
  int eh_esq;
  
  // primeira parte: encontrar p e pai
  if(T->raiz != NULL && get_valor(T->raiz->item) == chave) {
    pai = NULL;
    p = T->raiz;
  } else {
    pai = buscar_pai(T, chave);
    if(pai != NULL) {
      if(pai->esq != NULL && get_valor(pai->esq->item) == chave) {
        p = pai->esq;
        eh_esq = 1;
      } else {
        p = pai->dir;
        eh_esq = 0;
      }
    } else {
      p = NULL;
    }
  }
  
  // segunda parte: remover o no
  if(p == NULL) {
    return false;
  }
  // se tiver apenas um filho:
  if(p->esq == NULL && p->dir == NULL) {
    if(pai == NULL) {
      T->raiz = NULL;
    } else {
      if(eh_esq)
        pai->esq = NULL;
      else 
        pai->dir = NULL;
    }
    apagar_item(&(p->item));
    free(p);
  } else {
    if(p->esq != NULL) {
      set_valor(p->item, get_valor(p->esq->item));
      set_valor(p->esq->item, chave);
    } else {
      set_valor(p->item, get_valor(p->dir->item));
      set_valor(p->dir->item, chave);
    }
    return abb_remover(T, chave);
  }
  return true;
}

// função para buscar um item:
ITEM *abb_busca(ABB *T, int chave){
  NO* atual = T -> raiz;
  elem suspeito = get_valor(atual -> item);
  //printf("Itens lidos: ");
  while(suspeito != chave){
    suspeito = get_valor(atual -> item);
    //printf("%d ", suspeito);
    if(atual != NULL) {
      suspeito = get_valor(atual -> item);
      // se for igual:
      if (suspeito == chave){
        return (atual -> item);
      }
      //se for menor, ir pra esquerda:
      else if(suspeito > chave){
        atual = atual -> esq;
      }//senão, ir para a direita:
      else {                
        atual = atual -> dir;
      }
      // caso não for encontrado:
      if(atual == NULL){
        return NULL;
      }
    }     
  }
  return (T -> raiz -> item);
}