#include "cabezeraMD.h"

void asignarEstado(Proceso *scheduling){
    if(strcmp(scheduling->estado, "Nuevo") == 0){
        strcpy(scheduling->estado, "Listo");
    } 
    if(strcmp(scheduling->estado, "Listo") == 0 && scheduling->procesador != 0){
        strcpy(scheduling->estado, "Corriendo");
    }else if(strcmp(scheduling->estado, "Corriendo") == 0){
        strcpy(scheduling->estado, "Terminado");
    }
}
void ingresaProceso(Proceso *scheduling[]){
    static int id = 0;
    int i;
    for(i = 0; i < 10; i++){
        if(scheduling[i] == NULL){
            scheduling[i] = (Proceso*)malloc(sizeof(Proceso));
            if(scheduling[i] == NULL){
                printf("No se pudo asignar memoria.\n");
                exit(1);
            }
            strcpy(scheduling[i]->estado, "Nuevo" ); 
            scheduling[i]->idProceso = rand()%400 + 100;
            scheduling[i]->prioridad = ++id;
            scheduling[i]->procesador = 0;
            break;
        }
    }

}
int terminaProceso(Proceso *scheduling[], int posicion ){
    free(scheduling[posicion]);       
    scheduling[posicion] = NULL;
    return posicion;
 
}
void recorrerCola(Proceso *scheduling[]){
    int i, proces, fin, prior;
    proces = 0;
    for(i = 0; i < 10; i++){
        if(scheduling[i] != NULL){
            if(strcmp(scheduling[i]->estado, "Terminado") == 0){
                prior = scheduling[i]->prioridad + 1;
                fin = terminaProceso(scheduling, i);
            }
        }
    }
    
    for(i = 0; i < 10; i++){
        if(scheduling[i] != NULL){
            if(proces < 2 && ((scheduling[i]->prioridad == prior) || (scheduling[i]->prioridad == prior+1))){
                scheduling[i]->procesador = proces + 1;
                proces++;
            }else if(proces < 2){
                scheduling[i]->procesador = proces + 1;
                proces++;
            }
            asignarEstado(scheduling[i]);
           
        }
    }
    
}


void mostrarScheduler(Proceso *scheduling[]){
    int i;
    for(i = 0; i < 10; i++){
        if(scheduling[i] != NULL){
            printf("[%d]->{%d; %d; %d; %s}\n", i, scheduling[i]->procesador, scheduling[i]->idProceso, scheduling[i]->prioridad, scheduling[i]->estado);
        }else{
            printf("[%d]\n", i);
        }
    }
}