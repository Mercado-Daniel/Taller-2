#include "cabecera.h"

int main(void){
    cola *inicio, *final;
    inicio = NULL;
    final = NULL;

    enCola(&inicio, &final, 13);
    enCola(&inicio, &final, 12);
    enCola(&inicio, &final, 11);
    mostrarCola(inicio, final);
    desenCola(&inicio, &final);
    mostrarCola(inicio, final);
    vaciaCola(&inicio, &final);
    mostrarCola(inicio,final);
    enCola(&inicio, &final, 20);
    enCola(&inicio, &final, 21);
    enCola(&inicio, &final, 22);
    enCola(&inicio, &final, 23);
    enCola(&inicio, &final, 24);
    enCola(&inicio, &final, 25);
    enCola(&inicio, &final, 26);
    mostrarCola(inicio, final);
    desenCola(&inicio, &final);
    desenCola(&inicio, &final);
    desenCola(&inicio, &final);
    mostrarCola(inicio, final);

    return 0;
}