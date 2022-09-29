#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int **reservarM(int filas, int columnas);
void cargarM(int **mat, int filas, int columnas);
void mostraM(int **mat, int filas, int columnas);
int **expandir(int **matriz, int filas, int columnas);