#include "header.h"

void inserta(arbol **A, char pal[]){
    if(*A == NULL){//si el arbol no existe lo creo
        *A = (arbol*)malloc(sizeof(arbol));//creo el arbol
        strcpy((*A)->palabra, pal);//copio pal a palabra en la raiz
        (*A)->h_izq = NULL;//el hijo izquierdo inicia como null
        (*A)->h_der = NULL;//el hijo derecho inicia como null
    }else{//en caso de existir el arbol
        if(strcmp(pal, (*A)->palabra) < 0){
            inserta(&((*A)->h_izq), pal);
        }else if(strcmp(pal, (*A)->palabra) > 0){
            inserta(&((*A)->h_der), pal);
        }

    }
}

/*char esMiembro(arbol *A,char pal[]){
    if(A == NULL){
        return 'f';
    }else if(strcmp((A)->palabra, pal) == 0){
        return 'v';
    }else if(strcmp(pal, (A)->palabra) < 0){
        return esMiembro(A->h_izq, pal);
    }else{
        return esMiembro(A->h_der, pal);
    }
}*/

char* suprime_min(arbol **A){
    char *ref = (char*)malloc(LONG_MAX * sizeof(char));
    if((*A)->h_izq == NULL){
        strcpy(ref, (*A)->palabra);
        arbol *tmp = *A;
        *A = (*A)->h_der;
        free(tmp);
        return ref;
    }else{
        return suprime_min(&(*A)->h_izq);
    }
}

void suprime(arbol **A, char pal[]){
    if(*A != NULL){
        arbol *tmp = *A;
        if(strcmp(pal, (*A)->palabra) < 0){
            suprime(&((*A)->h_izq), pal);
        }else if(strcmp(pal, (*A)->palabra) > 0){
            suprime(&(*A)->h_der, pal);
        
        }else if((*A)->h_izq == NULL && (*A)->h_der == NULL){
                *A = NULL;
                free(tmp);
        }else if((*A)->h_izq == NULL){
            *A = (*A)->h_der;
            free(tmp);
        }else if((*A)->h_der == NULL){
            *A = (*A)->h_izq;
            free(tmp);
        }else{
            strcpy((*A)->palabra ,suprime_min(&((*A)->h_der)));
        }
    }
}