#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sgte;  
    
}lista;

void insertar(int, lista **);
void listar(lista *);
void eliminar(int, lista **);

