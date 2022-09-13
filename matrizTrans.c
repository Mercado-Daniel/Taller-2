#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 10

int **reservar(int filas, int columnas);
void cargar(int filas, int columnas, int **mat);
void mostrar(int filas, int columnas, int **mat);
void transpuesta(int filas, int columnas, int **mat, int **trans);
void liberar(int filas, int **mat);

int main(void){
    srand(getpid());
    int **mat, **trans;
    int filas,columnas;

    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);

    printf("Matriz Original:\n");
    mat = reservar(filas, columnas);
    cargar(filas, columnas, mat);
    mostrar(filas, columnas, mat);
    printf("\nMatriz Transpuesta:\n");    
    trans = reservar(columnas, filas);
    transpuesta(filas, columnas, mat, trans);
    mostrar(columnas, filas, trans);
    
    liberar(filas, mat);
    liberar(columnas, trans);

}

int **reservar(int filas, int columnas){
    int i;
    int **mat;
    mat = (int**)malloc(filas * sizeof(int*));
    if(mat == NULL){
        printf("No se pudo reservar memoria");
        exit(1);
    }
    for(i = 0; i < filas; i++){
        *(mat + i) = (int*)malloc(columnas * sizeof(int));
    }
    return mat;
}

void cargar(int filas, int columnas, int **mat){
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            *(*(mat + i) + j) = rand()%N;
        }
    }
}
void mostrar(int filas, int columnas, int **mat){
    int i, j;
    for(i = 0; i < filas; i++){
        printf("[ ");
        for(j = 0; j < columnas; j++){
            printf("%d ", *(*(mat + i) + j));
        }
        printf("]\n");
    }
}

void transpuesta(int filas, int columnas, int **mat, int **trans){
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            *(*(trans + j) + i) = *(*(mat + i) + j);
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