#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sgte;
}cola;

void enCola(cola **, cola **, int);
int desenCola(cola **, cola **);/*
void vaciaCola(cola **);
int tamanio(cola *);
int estaVacia(cola **);
int frente(cola *);*/
void mostrarCola(cola *, cola *);
