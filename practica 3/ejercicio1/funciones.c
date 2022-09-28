#include "uno.h"

int compara_tiempos(Tiempo *t1, Tiempo *t2){
    int aux;
    aux = comparar(t1->anio, t2->anio);
    if(aux == 1 || aux == -1){
        return aux;
    }
    aux = comparar(t1->mes, t2->mes);
    if(aux == 1 || aux == -1){
        return aux;
    }
    aux = comparar(t1->dia, t2->dia);
    if(aux == 1 || aux == -1){
        return aux;
    }
    aux = comparar(t1->hora, t2->hora);
    if(aux == 1 || aux == -1){
        return aux;
    }
    aux = comparar(t1->minuto, t2->minuto);
    if(aux == 1 || aux == -1){
        return aux;
    }
    aux = comparar(t1->segundo, t2->segundo);
    return aux;
    
}

int comparar(int t1, int t2){
    if(t1 > t2){
        return -1;
    }else if(t1 < t2){
        return 1;
    }else{
        return 0;
    }
}

void imprime_tiempo(Tiempo t){
    printf("%d/%d/%d %d:%d:%d \n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

void ordena_alfa(Archivo *lista, int n){
    int i, j;
    Archivo temp;
    for(i = 0; i < n-1; i++){
        for(j = 1; j < n; j++){
            if(strcmp(lista[j-1].nombre, lista[j].nombre) > 0){
                temp = lista[j-1];
                lista[j-1] = lista[j];
                lista[j] = temp;
            }
        }
    }

}

void ordena_temporal(Archivo *lista, int n){
    int i, j , aux;
    Archivo temp;
    for(i = 0; i < n-1; i++){
        for (j = 1; j < n; j++){
            aux = compara_tiempos(&lista[j-1].ultima_mod, &lista[j].ultima_mod);
            if(aux == -1){
                temp = lista[j-1];
                lista[j-1] = lista[j];
                lista[j] = temp;
            }
        }
    }
    
}