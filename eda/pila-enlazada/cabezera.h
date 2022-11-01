#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sgte;
}pila;

void apila(pila **, int);
int desapila(pila **);
void vaciaPila(pila **);
int tamanio(pila *);
int estaVacia(pila **);
int cima(pila *);
void mostrarPila(pila *);
