#include "cabezeraMD.h"

int main(void){
    int i;
    srand(getpid());
    Proceso *scheduling[10];
    for(i = 0; i < 10; i++){
        scheduling[i] = NULL;
    }
    for(i = 0; i < 4; i++){
        printf("%d \n", i);
        ingresaProceso(scheduling);
        ingresaProceso(scheduling);
        ingresaProceso(scheduling);
        mostrarScheduler(scheduling);
        printf("\n");
        recorrerCola(scheduling);
        mostrarScheduler(scheduling);
        printf("\n");
        ingresaProceso(scheduling);
        ingresaProceso(scheduling);
        mostrarScheduler(scheduling);
        printf("\n");
        recorrerCola(scheduling);
        mostrarScheduler(scheduling);
        printf("\n");
        recorrerCola(scheduling);
        mostrarScheduler(scheduling);
    }
        

    return 0;
}
