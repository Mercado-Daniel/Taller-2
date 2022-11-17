#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LONG_MAX 25

typedef struct nodo{
    char palabra[LONG_MAX];
    struct nodo *h_izq, *h_der;
}arbol;

void inserta(arbol **, char[]);
char esMiembro(arbol **, char[]);
void suprime(arbol **, char[]);
char* suprime_min(arbol **);
void listar(arbol *);