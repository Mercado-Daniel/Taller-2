#include "header.h"

void insertar(int d, listaD **i){
    if(*i == NULL){
        printf("Insertando %d en la lista\n", d);
        *i = (listaD*)malloc(sizeof(listaD));
        (*i)->dato = d;
    }else{
        if((*i)->dato > d){
            listaD *nuevo = (listaD*)malloc(sizeof(listaD));
            nuevo->dato = d;
            nuevo->sgte = *i 
        }
    }
}