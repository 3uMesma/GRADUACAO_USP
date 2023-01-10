#include <stdio.h>
#include <stdlib.h>
#include "DMconfig.h"

struct dm_matrix{
    int n,m;
    ITEM **matrix;
};
DM_MATRIX *matrixconfig_create(int n, int m, ITEM fullyby){
    ITEM** matrix = (ITEM**) malloc(sizeof(ITEM*)*n);
    for(int i=0;i<n;i++){
        matrix[i] = (ITEM*)malloc(sizeof(ITEM)*m);
        for(int j=0;j<m;j++){
            matrix[i][j] = fullyby;
        }
    }
    DM_MATRIX *dm = malloc(sizeof(DM_MATRIX));
    dm->n=n;
    dm->m=m;
    dm->matrix=matrix;
    return dm;
}
int matrixconfig_getN(DM_MATRIX *dm){
    return dm->n;
}
int matrixconfig_getM(DM_MATRIX *dm){
    return dm->m;
}
void matrixconfig_free(DM_MATRIX **dm){
    assert(dm!=NULL);
    for(int i=0;i<(*dm)->n;i++){
        free((*dm)->matrix[i]);
    }
    free((*dm)->matrix);
    free((*dm));
    *dm=NULL;
}
void matrixconfig_set(DM_MATRIX *dm,int x, int y, ITEM value){
    dm->matrix[x][y]=value;
}
ITEM matrixconfig_get(DM_MATRIX *dm,int x, int y){
    return dm->matrix[x][y];
}
void matrixconfig_print(DM_MATRIX *dm){
    for(int i=0;i<dm->n;i++){
        for(int j=0;j<dm->m;j++){
            printf("%.1f ",dm->matrix[i][j]);
        }
        printf("\n");
    }
}
void matrixconfig_randomize(DM_MATRIX *dm){
    for(int i=0;i<dm->n;i++){
        for(int j=0;j<dm->m;j++){
            if(i==j){
                dm->matrix[i][j]=0;
            }else if(dm->matrix[i][j]==-1){
                ITEM r_value = rand()%100+2;
                dm->matrix[i][j]=r_value;
                dm->matrix[j][i]=r_value;
            }
        }
    }
}
void matrixconfig_cleardiagonal(DM_MATRIX *dm){
    for(int i=0;i<dm->n;i++){
        for(int j=0;j<dm->m;j++){
            if(i==j){
                dm->matrix[i][j]=0;
            }
        }
    }
}