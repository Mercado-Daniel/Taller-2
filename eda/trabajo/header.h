#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo{
    char voto;
    char nombre[10];
    struct nodo *sgte;
}politico;

void insertar(char[10], politico **);
void suprimir(char[10], politico **);
int miembro(char[10], politico *);
void mostrar(politico *);