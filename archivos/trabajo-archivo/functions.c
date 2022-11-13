#include "header.h"

int calcularPago(char planPe, int meses, int edad){
    FILE *pl;
    pl = fopen("plan.txt", "r");
    char *planPl = (char*)malloc(sizeof(char));
    int *montoPl = (int*)malloc(sizeof(int));
    if(pl != NULL){
        while(planPl != planPe){
            fscanf(pl, "%c %d", planPl, montoPl);
        }

        if(edad > 65 || edad < 12){

        }else{
            
        }
    }
}