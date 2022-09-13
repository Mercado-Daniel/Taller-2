#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 10

int **reservar(int filas);
void rellenar(int filas, int **mat);
void mostrar(int filas, int **mat);
void sumaMatrices(int filas, int **A, int **B, int **suma);
void liberar(int filas, int **mat);

int main(void){
    srand(getpid());
    int filas;
    int **matA, **matB, **suma;

    printf("Ingrese el numero de filas de las matrices cuadradas");
    scanf("%d", &filas);

    matA = reservar(filas);
    rellenar(filas, matA);
    mostrar(filas, matA);
    printf("\n");
    matB = reservar(filas);
    rellenar(filas, matB);
    mostrar(filas, matB);
    printf("\n");
    suma = reservar(filas);
    sumaMatrices(filas, matA, matB, suma);
    mostrar(filas, suma);
    liberar(filas, matA);
    liberar(filas, matB);
    liberar(filas, suma);

    return EXIT_SUCCESS;
}

int **reservar(int filas){
    int i;
    int **mat;
    mat = (int**)malloc(filas * sizeof(int*));
    if(mat == NULL){
        printf("NO se pudo reservar memoria");
        exit(1);
    }
    for(i = 0; i < filas; i++){
        *(mat + i) = (int*)malloc(filas * sizeof(int));
        if(*(mat + i) == NULL){
        printf("NO se pudo reservar memoria");
        exit(1);
    }
    }
    return mat;
}

void rellenar(int filas, int **mat){
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < filas; j++){
            *(*(mat + i) + j) = rand()%N;
        }
    }
}

void mostrar(int filas, int **mat){
    int i, j;
    for(i = 0; i < filas; i++){
        printf("[ ");
        for(j = 0; j < filas; j++){
           printf("%2d ", *(*(mat + i) + j));
        }
        printf("]\n");
    }
}

void sumaMatrices(int filas, int **A, int **B, int **suma){
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < filas; j++){
            *(*(suma + i) + j) = *(*(A + i) + j) + *(*(B + i) + j) ;
        }
    }
}

void liberar(int filas, int **mat){
    int i;
    for(i = 0; i < filas; i++){
        free(*(mat + i));
    }
    free(mat);
}