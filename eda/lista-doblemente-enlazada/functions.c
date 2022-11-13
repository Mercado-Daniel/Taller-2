#include "header.h"

void insertar(int d, listaD **i){
    if(*i == NULL){
        printf("Insertando %d en la lista\n", d);
        (*i)->dato = d;
    }else{
        listaD *nuevo = (listaD*)malloc(sizeof(listaD));
        if((*i)->dato > d){
            printf("Insertando %s en la lista\n", d);
            nuevo->dato = d;
            nuevo->sgte = *i;
            nuevo->ant = 
            *i = nuevo;
            
        }else if((*i)->dato < d && (*i)->sgte != NULL && (*i)->sgte->dato > d){
            nuevo->dato = d;
            nuevo->sgte = (*i)->sgte;
            (*i)->sgte = nuevo;
        }else if((*i)->dato == d){
            printf("Ya existe el elemento %d en la lista\n", d);
        }else{
            insertar(d, &(*i)->sgte);
        }
    }
}