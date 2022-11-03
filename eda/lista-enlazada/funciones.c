#include "cabecera.h"

void insertar(int d, lista **i){//es recursiva se encarga de insertar nodos en la lista
    if(*i == NULL){//si la lista esta vacia solo le asigno el dato al primer nodo
        printf("Insertado %d en la lista\n", d);
        *i = (lista*)malloc(sizeof(lista));
        (*i)->dato = d;
    }else{//en caso de que la lista no este vacia 
        if((*i)->dato > d){//si el dato del nuevo nodo es menor al dato del nodo i
            printf("Insertando %d en la lista\n", d);
            lista *nuevo = (lista*)malloc(sizeof(lista));//genero un nuevo nodo para la lista
            nuevo->dato = d;//le asigno d como dato al nuevo nodo
            nuevo->sgte = *i;//hago que el nuevo nodo apunte al nodo i  
            *i = nuevo;//hago que el nodo i sea igual al nuevo nodo
        }else if((*i)->dato < d && (*i)->sgte != NULL && (*i)->sgte->dato > d){//si d en mayor a dato i y i->sgte es distinto de NULL y i el dato del nodo al que apunta i es mayor a d
            printf("Insertando %d en la lista\n", d);//sirve para ubicar el nuevo nodo entre el mayor y el menor nodo mas proximo
            lista *nuevo = (lista*)malloc(sizeof(lista));
            nuevo->dato = d;//asigno d como dato al nuevo nodo
            nuevo->sgte = (*i)->sgte;//nuevo sgte es igual a i sgte
            (*i)->sgte = nuevo;//i sgte se iguala a nuevo
        }else if((*i)->dato == d){//no permito que los nodos tengan datos repetidos
            printf("Ya existe el elemento %d en la lista\n", d);
        }else{//si no se da ninguna de las opciones recorro la lista y pruevo con insertarlo despues de otro nodo
            insertar(d, &(*i)->sgte);
        }
    }
}

void listar(lista *i){
    if(i != NULL){
        printf("Elemento = %d\n", i->dato);
        listar(i->sgte);//uso la recursividad para recorrer la lista
    }
}

void eliminar(int d, lista **i){
    if(*i == NULL){
        printf("No existe el elemento a eliminar\n");
    }else{
        if((*i)->dato == d){
            printf("Elimino a %d\n", d);
            lista *aux = (*i);//hago que aux se iguale a i
            (*i) = (*i)->sgte;//i se convierte en el nodo al que apunta para que no se pierda
            free(aux);//libero el auxiciliar eliminanodo el nodo
        }else if((*i)->dato < d && (*i)->sgte != NULL && (*i)->sgte->dato == d){
            printf("Elimino a %d\n", d);
            lista *aux = (*i)->sgte;
            (*i)->sgte = (*i)->sgte->sgte;
            free(aux);
        }else{
            eliminar(d, &(*i)->sgte);
        }
    }
}