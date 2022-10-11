#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef struct{
    int procesador;
    int idProceso;
    int prioridad;
    char estado[10];
}Proceso;

void asignarEstado(Proceso *scheduling);
void ingresaProceso(Proceso *scheduling[]);
void terminaProceso(Proceso *scheduling[], int posicion);
void recorrerCola(Proceso *scheduling[]);
void mostrarScheduler(Proceso *scheduling[]);