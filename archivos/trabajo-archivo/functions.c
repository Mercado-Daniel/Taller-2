#include "header.h"

float* calcularPago(char *planPe, int *meses, int *edad){
    FILE *pl;
    pl = fopen("plan.txt", "r");
    char *planPl = (char*)malloc(sizeof(char));
    int *montoPl = (int*)malloc(sizeof(int));
    float *monto = (float*)malloc(sizeof(float));
    while(*planPl != *planPe){
        fscanf(pl, "%c %d", planPl, montoPl);
        if(feof(pl)){
            break;
        }
    }
    if(*edad > 65 || *edad < 12){
        if(*meses > 24){
            *monto = *montoPl -((50.0/100.0) * (*montoPl));
        }else{
            *monto = *montoPl -((5.0/100.0) * (*montoPl));
        }
    }else{
        if(*meses > 24){
            *monto = *montoPl -((45.0/100.0) * (*montoPl));
        }else{
            *monto = *montoPl;
        }
    }

    return monto;
}