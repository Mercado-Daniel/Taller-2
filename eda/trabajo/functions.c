#include "header.h"

void insertar(char nombre[10], politico **lista){
    if(*lista == NULL){
        *lista = (politico*)malloc(sizeof(politico));
        strcpy((*lista)->nombre, nombre);
        printf("Se agrego %s a la lista\n", (*lista)->nombre);
    }else{
        if(strcmp((*lista)->nombre, nombre) == 0){
            printf("%s ya se encuentra en la lista.\n", nombre);
        }else if((*lista)->sgte != NULL){
            politico *nuevo = (politico*)malloc(sizeof(politico));
            strcpy(nuevo->nombre, nombre);
            nuevo->sgte = (*lista)->sgte;
            (*lista)->sgte = nuevo;
            printf("Se agrego %s a la lista\n", nuevo->nombre);
        }else{//utiliso recursividad para recorer la lista
            insertar(nombre, &(*lista)->sgte);
        }
        
    }
}

void suprimir(char nombre[10], politico **lista){
    if(*lista == NULL){
       printf("No hay politico para eliminar");
    }else{
        if(strcmp((*lista)->nombre, nombre) == 0){
            politico *fuera = (*lista);
            (*lista) = (*lista)->sgte;
            printf("Se elimino a %s\n",fuera->nombre);
            free(fuera);
        }else{
            suprimir(nombre, &(*lista)->sgte);
        }
    }
}

void mostrar(politico *lista){
    politico *temp;
    temp = lista;
    while(temp != NULL){
        printf("%s\n", temp->nombre);
        temp = temp->sgte;
    }
}

int miembro(char nombre[10], politico *lista){
    politico *temp = NULL;
    temp = lista;
    while(temp != NULL){
        if(strcmp((lista)->nombre, nombre) == 0){
            return 1;
        }else{
            temp = temp->sgte;
        }
    }
    return 0;  
}