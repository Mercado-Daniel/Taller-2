#include "cabezera.h"

int **reservarM(int filas, int columnas){
    int **mat;
    int i;
    mat = (int **)malloc(filas * sizeof(int *));
    if (mat == NULL){
        printf("No se pudo reservar memoria");
        exit(1);
    }
    for (i = 0; i < filas; i++){
        *(mat + i) = (int *)malloc(columnas * sizeof(int));
    }
    return mat;
}

void cargarM(int **mat, int filas, int columnas){
    int i, j;
    for (i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            *(*(mat + i) + j) = rand() % 10 + 1;
        }
    }
}

void mostraM(int **mat, int filas, int columnas){
    int i, j;
    for (i = 0; i < filas; i++){
        printf("[ ");
        for (j = 0; j < columnas; j++){
            printf("%2d ", *(*(mat + i) + j));
        }
        printf("]\n");
    }
}

int **expandir(int **matriz, int filas, int columnas){
    int i;
    matriz = (int **)realloc(matriz, (filas + 1) * sizeof(int *));
    if (matriz == NULL){
        printf("No se pudo redimencionar la matriz");
        exit(1);
    }
    for (i = 0; i < filas + 1; i++){
        *(matriz + i) = (int *)realloc(*(matriz + i) ,(columnas + 1) * sizeof(int));
        if (*(matriz + i) == NULL){
            printf("No se pudo reservar memoria");
            exit(1);
        }
    }
    for (i = 0; i < filas + 1; i++){
         *(*(matriz + i) + columnas) = 0;
    }

    return matriz;
}
