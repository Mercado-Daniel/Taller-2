#include "cabecera.h"

int main(void){
    pila *cima;
    cima = NULL;

    apila(&cima, 5);
    apila(&cima, 7);
    mostrarPila(cima);
    printf("\n");
    vaciaPila(&cima);
    mostrarPila(cima);
    printf("\n");
    apila(&cima, 10);
    mostrarPila(cima);
    printf("\n");
    desapila(&cima);
    mostrarPila(cima);
    printf("\n");
    apila(&cima, 12);
    apila(&cima, 75);
    apila(&cima, 37);
    mostrarPila(cima);
    printf("\n");

    return 0;
}