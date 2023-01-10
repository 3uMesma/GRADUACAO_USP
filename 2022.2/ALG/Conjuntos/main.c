#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
int main(){
    CONJUNTO *A = conjunto_create();
    CONJUNTO *B = conjunto_create();
    int n_a,n_b,op;
    ITEM_TIPO x;//O tipo do item está definido como 'int' no TAD item.h
    
    scanf("%d %d",&n_a,&n_b);
    for(int i=0;i<n_a;i++){
        scanf("%d",&x);
        conjunto_inserir(A,item_create(x));
    }
    for(int i=0;i<n_b;i++){
        scanf("%d",&x);
        conjunto_inserir(B,item_create(x));
    }
    scanf("%d",&op);
    ITEM_TIPO num;CONJUNTO *C;
    printf("conjunto A: ");conjunto_print(A);printf("\n");
    printf("conjunto B: ");conjunto_print(B);printf("\n");
    switch(op){
        case 1://pertence
            scanf("%d",&num);
            if(conjunto_pertence(A,item_create(num))){
                printf("Pertence.");
            }else{
                printf("Não Pertence.");
            }
            break;
        case 2://uniao
            C = conjunto_uniao(A,B);
            conjunto_print(C);
            conjunto_free(&C,false);
            break;
        case 3://interseccao
            C = conjunto_interseccao(A,B);
            conjunto_print(C);
            conjunto_free(&C,false);
            break;
        case 4://remover
            scanf("%d",&num);
            conjunto_remover(A,item_create(num));
            conjunto_print(A);
            break;
    }
    conjunto_free(&A,true);
    conjunto_free(&B,true);
    return 0;
}