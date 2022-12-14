#include "header.h"

int main(void){
    FILE *pe, *d;
    pe = fopen("personas.txt", "r");
    d = fopen("destino.txt", "w");
    char nombre[100];
    char apellido[100];
    char sexo[100];
    int *edad = (int*)malloc(sizeof(int));
    int *meses = (int*)malloc(sizeof(int));
    char *planPe = (char*)malloc(sizeof(char));
    float* monto = (float*)malloc(sizeof(float));

    if(pe == NULL){
        printf("No se pudo leer el archivo");
        exit(1);
    }
    fscanf(pe, "%s %s %d %s %d %c", nombre, apellido, edad, sexo, meses, planPe);
    while (!feof(pe)){
        monto = calcularPago(planPe, meses, edad);
        printf("%s %s %d %s %d %c %.2f\n", nombre, apellido, *edad, sexo, *meses, *planPe, *monto);
        fprintf(d, "%s %s %d %s %d %c %.2f\n", nombre, apellido, *edad, sexo, *meses, *planPe, *monto);
        fscanf(pe, "%s %s %d %s %d %c", nombre, apellido, edad, sexo, meses, planPe);
    }
    fclose(pe);
    fclose(d);
    free(edad);
    free(meses);
    free(planPe);
    free(monto);
    return 0;
}