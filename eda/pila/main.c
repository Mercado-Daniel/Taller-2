#include "cabezera.h"
#include "funciones.c"

int main(void){
    apila(3);
    apila(12);
    mostrarPila();
    desapila();
    apila(6);
    apila(1);
    apila(7);
    mostrarPila();
    desapila();
    desapila();
    mostrarPila();
    vaciaPila();
    mostrarPila();

    return 0;
}