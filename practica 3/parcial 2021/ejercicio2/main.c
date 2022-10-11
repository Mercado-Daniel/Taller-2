#include "cabezera.h"

int main(void){
    srand(getpid());
    int **mat;
    int filas, columnas;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);
    
    mat = reservarM( filas, columnas);
    cargarM(mat, filas, columnas);
    mostraM(mat, filas, columnas);
    printf("\n");
    mat = expandir(mat, filas, columnas);
    mostraM(mat, filas + 1, columnas + 1);
    liberarM(mat, filas + 1, columnas + 1);

}