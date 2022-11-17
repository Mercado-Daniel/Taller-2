#include<stdio.h>
#include<stdlib.h>

#define LONG_MAX 25;

typedef struct nodo{
    int dato;
    struct nodo *h_izq, *h_der;
    
}arbol;

void inserta(arbol **, int);
int es_miembro(arbol *, int);
void suprime(arbol **, int);
int suprime_min(arbol **);
void inorder(arbol *);
void preorder(arbol *);
void postorder(arbol *);