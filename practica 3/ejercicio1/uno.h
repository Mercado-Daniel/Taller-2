#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int anio, mes, dia, hora, minuto, segundo;
}Tiempo;

typedef struct{
    char *nombre;
    Tiempo ultima_mod;
}Archivo;

int compara_tiempos(Tiempo *t1, Tiempo *t2);
int comparar(int t1, int t2);
void imprime_tiempo(Tiempo t);
void ordena_alfa(Archivo *lista, int n);
void ordena_temporal(Archivo *lista, int n);
