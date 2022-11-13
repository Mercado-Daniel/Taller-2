#include "cabecera.h"


void apila(pila **p, int tam){
    pila *temp = NULL;
    temp = (pila*)malloc(sizeof(pila));
    temp->dato = tam;
    temp->sgte = *p;
    *p = temp;
}
int desapila(pila **p){//sustrae p de la pila y lo guarda en un nodo temporal qu 
    pila *temp = NULL;
    int tam = 0;
    temp = *p;//igualo el temp a la pila
    *p = (*p)->sgte;//igualo la pila al siguiente nodo
    tam = temp->dato;//guardo dato en tam
    free(temp);//libero temp despues de haber
    return tam;
}
void vaciaPila(pila **p){
    while( estaVacia(p) == 0){
        desapila(p);
    }      
}
int tamanio(pila *p){
    int cont;
    cont = 0;
    while (p != NULL){
        cont +=1;
        p = p->sgte;
    }
    return cont;
    
}
int estaVacia(pila **p){
    if(tamanio(*p) > 0){
        return 0;
    }
    return 1;
}
int cima(pila *p){
    return p->dato;
}
void mostrarPila(pila *p){
    printf("Tamanio = %d\n", tamanio(p));
    if(tamanio(p) > 0){
        printf("Cima = %d\n", cima(p));
        while(p != NULL){
            printf("%d\n", p->dato);
            p = p->sgte;
        }
    }
}