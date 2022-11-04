#include "header.h"

int main(void){
    politico *chicosBuenos, *chicosMalos;
    chicosBuenos = NULL;
    chicosMalos = NULL;

    insertar("Daniel", &chicosBuenos); 
    insertar("Yair", &chicosBuenos);
    insertar("Adrian", &chicosBuenos);
    insertar("Daniel", &chicosBuenos);
    insertar("Tiziano", &chicosBuenos);
    mostrar(chicosBuenos);
    printf("\n");
    suprimir("Yair", &chicosBuenos);
    mostrar(chicosBuenos);
    printf("%d\n", miembro("Yair", chicosMalos));
    printf("%d\n", miembro("Daniel", chicosMalos));

}