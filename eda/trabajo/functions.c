#include "header.h"

void insertar(char nombre[], politico **lista){
    if(*lista == NULL){
        *lista = (politico*)malloc(sizeof(politico));
        strcpy((*lista)->nombre, nombre);
        printf("Se agrego %s a la lista\n", (*lista)->nombre);
    }else{
        /*if(miembro(nombre, *lista)){
            printf("%s ya se encuentra en la lista.\n", nombre);
        }else */
        if((*lista)->sgte != NULL){
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

void suprimir(char nombre[], politico **lista){
    if(*lista == NULL){
       printf("No hay politico para eliminar\n");
    }else{
        if(miembro(nombre, *lista)){
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
    if(lista != NULL){
        while(temp != NULL){
            printf("%s\n", temp->nombre);
            temp = temp->sgte;
        }
    }else{
        printf("Lista vacia\n");
    }
}

int miembro(char nombre[], politico *lista){
    politico *temp = NULL;
    temp = lista;
    if(lista != NULL){
        while(temp != NULL){
            if(strcmp((temp)->nombre, nombre) == 0){
                return 1;
            }else{
                temp = temp->sgte;
            }
        }
    }
    return 0;  
}

void elegirLIsta(char voto,char nombre[],politico **buenos,politico **malos){
    if(voto == 'f'){
        if(miembro(nombre, *malos) && miembro(nombre, *buenos) == 0){
            suprimir(nombre, malos);
            insertar(nombre, buenos);
        }else if(miembro(nombre, *buenos)){
            printf("%s se matiene en los chicos buenos\n", nombre);
        }else {
            printf("2");
            insertar(nombre, buenos);
        }
    }else if(voto == 'd'){
        if( miembro(nombre, *buenos) && miembro(nombre, *malos) == 0){
            suprimir(nombre, buenos);
            insertar(nombre, malos);
        }else if(miembro(nombre, *malos)){
            printf("%s se matiene en los chicos buenos\n", nombre);
        }else{
            printf("4");
            insertar(nombre, malos);
        }
    }else{
    }
    
}
