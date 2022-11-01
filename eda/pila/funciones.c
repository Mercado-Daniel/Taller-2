#include "cabezera.h"

void apila(int elemento){
    if(tamanio() == CAPACIDAD){
        printf("No caben mas elementos en la pila.");
    }
    cima += 1;
    elementos[cima] = elemento;
}
int desapila(){
    if(estaVacia()){
        printf("No hay elementos.");
    }
    cima -= 1;
    return elementos[cima+1];
}
void vaciaPila(){
    cima = -1;
}
int tamanio(){
    return cima+1;
}
int estaVacia(){
    return cima == -1;
}
int cima1(){
    if(estaVacia()){
        printf("La pila esta vacia por lo tanto no hay cima.");
    }
    return elementos[cima];
}
void mostrarPila(){
    int i;
    printf("Tamanio = %d\nCima = %d\n[ ", tamanio(), cima1());
    for(i = 0; i < cima; i++){
        printf("%d ", elementos[i]);
    }
    printf("]\n");
}