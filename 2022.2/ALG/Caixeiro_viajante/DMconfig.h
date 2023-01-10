#ifndef DMCONFIG_H
    #define DMCONFIG_H
    #include <assert.h>
    typedef float ITEM;//mude aqui caso queira que tudo rode com base em inteiros, doubles etc
    typedef struct dm_matrix DM_MATRIX;
    DM_MATRIX *matrixconfig_create(int n, int m, ITEM fullyby);
    int matrixconfig_getN(DM_MATRIX *dm);
    int matrixconfig_getM(DM_MATRIX *dm);
    void matrixconfig_free(DM_MATRIX **dm);
    void matrixconfig_set(DM_MATRIX *dm,int x, int y, ITEM value);
    ITEM matrixconfig_get(DM_MATRIX *dm,int x, int y);
    void matrixconfig_print(DM_MATRIX *dm);
    void matrixconfig_randomize(DM_MATRIX *dm);
    void matrixconfig_cleardiagonal(DM_MATRIX *dm);
#endif