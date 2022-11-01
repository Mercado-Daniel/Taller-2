#include "cabezera.h"

int main(void){
    cola *inicio, *final;
    inicio = NULL;
    final = NULL;

    enCola(&inicio, &final, 13);
    enCola(&inicio, &final, 12);
    enCola(&inicio, &final, 11);
    mostrarCola(inicio, final);
    mostrarCola(inicio, final);

    return 0;
}