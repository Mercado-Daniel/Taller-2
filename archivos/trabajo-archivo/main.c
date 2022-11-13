#include "header.h"

int main(void){
    FILE *pe, *d;
    pe = fopen("personas.txt", "r");
    d = fopen("destino.txt", "r+");
    char nombre[100];
    char apellido[100];
    char sexo[100];
    int *edad = (int*)malloc(sizeof(int));
    int *meses = (int*)malloc(sizeof(int));
    char *planPe = (char*)malloc(sizeof(char));
    int monto;

    if(pe != NULL){
        fscanf(pe, "%s %s %d %s %d %c", nombre, apellido, edad, sexo, meses, planPe);
        while (!feof(pe)){
            monto = calcularPago(planPe, meses, edad);
            fprintf(d, "%s %s %d %s %d %c %d\n", nombre, apellido, edad, sexo, meses, planPe, monto);
        }
        
    }
    
}