#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 10

int ** productoEscalar(int filas, int columnas, int escalar, int **mat);

int main(void){
    srand(getpid());
    int filas, columnas, escalar, i, j;
    int **mat;

    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);
    printf("Ingrese el escalar: ");
    scanf("%d", &escalar);

    mat = (int**)malloc(filas * sizeof(int*));
    if(mat == NULL){
        printf("No se pudo reservar memoria");
        return EXIT_FAILURE;
    }
    for(i = 0; i < filas; i++){
        *(mat + i) = (int*)malloc(columnas * sizeof(int));
        if(*(mat + i) == NULL){
            printf("No se pudo reservar memoria");
            return EXIT_FAILURE;
        }
    }
    for(i = 0; i < filas; i++){
        printf("[ ");
        for(j = 0; j < columnas; j++){
            *(*(mat + i) + j) = rand()%N;
            printf("%d ", *(*(mat + i) + j));
        }
        printf("]\n");
    }

    printf("\n");
    mat = productoEscalar(filas, columnas, escalar, mat);

    for(i = 0; i < filas; i++){
        printf("[ ");
        for(j = 0; j < columnas; j++){
            printf("%2d ", *(*(mat + i) + j));
        }
        printf("]\n");
    }

    for(i = 0; i < filas; i++){
        free(*(mat + i));
    }
    free(mat);

    return 0;
}

int ** productoEscalar(int filas, int columnas, int escalar, int **mat){
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            *(*(mat + i) + j) = *(*(mat + i) + j) * escalar;
        }
    }

    return mat;
}