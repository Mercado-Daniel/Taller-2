#include "cabezera.h"

void enCola(cola **inicio, cola **final, int entero){
    cola *temp = NULL;
    temp = (cola*)malloc(sizeof(cola));
    temp->dato = entero;
    temp->sgte = *final;
    *final = temp;
    if( *inicio == NULL){
        *inicio = temp;
    }
}
int desenCola(cola **inicio, cola **final){
    cola *temp = NULL;
    int tam = 0;
    temp = *inicio;
    *inicio = (*inicio)->sgte;
    tam = temp->dato;
    free(temp);
    return tam;
}
/*void vaciaCola(cola **){

}
int tamanio(cola *){

}
int estaVacia(cola **){

}
int frente(cola *){

}*/
void mostrarCola(cola *ini, cola *f){
    cola *i = (cola*)malloc(sizeof(cola));
    i = ini;
    while(i != f){
            printf("%d\n", i->dato);
            i = i->sgte;
    }
}