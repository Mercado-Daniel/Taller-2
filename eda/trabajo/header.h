#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo{
    char voto;
    char nombre[10];
    struct nodo *sgte;
}politico;

void elegirLIsta(char,char [],politico **,politico **);
void insertar(char[], politico **);
void suprimir(char[], politico **);
int miembro(char[], politico *);
void mostrar(politico *);