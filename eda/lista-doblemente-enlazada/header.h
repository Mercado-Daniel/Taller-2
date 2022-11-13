#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sgte;
    struct nodo *ant;
    
}listaD;

void insertar(int, listaD **i);
void listar(listaD);
void eliminar(int , listaD**);
