#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <assert.h>

#define VERTICES 6

typedef struct arista{
    int verticeU;
    int verticeV;
    int costo;
}Arista;

typedef struct grafo{
     Arista *a;
     struct grafo *sig;
}Grafo;

typedef struct subconjunto{
    int raiz;
    int altura;
}Subconjunto;


void inserta(int , int , int, Grafo** );
void mostrar(Grafo*);
Arista* creaArista(int, int, int);
int encuentra(Subconjunto*, int ); 
void unir(Subconjunto*, int, int);
void kruskal(Grafo**);
