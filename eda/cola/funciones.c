#include "cabecera.h"

void enCola(cola **inicio, cola **final, int entero){
    cola *temp = NULL;
    temp = (cola*)malloc(sizeof(cola));
    temp->dato = entero;//almaceno el entero en el dato de temp
    if( *inicio == NULL){//en caso de que no aya inicio
        *inicio = temp;//temp se convierte en el inicio
        temp->sgte = *final;//temp->sgte apunta a final
    }else{//en caso de que aya inicio 
        (*final)->sgte = temp;//final->sgte apunta temp
        temp->sgte = NULL;//temp -> sgte no apunta an nada ya que se encuentra al final de la cola
    }
    *final = temp;//temp se iguala a final ya que final apunta si o si al ultimo nodo agregado
}
int desenCola(cola **inicio, cola **final){
    cola *temp = NULL;
    int tam = 0;
    temp = *inicio;//igualo temp a inicio
    *inicio = (*inicio)->sgte;//cambio el inicio al proximo nodo
    tam = temp->dato;//tam guarda el dato del nodo a eliminar
    free(temp);//libero y borro el nodo
    return tam;//retorno el dato del nodo eliminado 
}
void vaciaCola(cola **inicio, cola **final){
    while(*inicio != (*final)->sgte){
        desenCola(inicio, final);
    }
}
int tamanio(cola *inicio){
   int contador = 0;
   cola *i = (cola*)malloc(sizeof(cola));
   i = inicio;
   while(i != NULL){
        contador +=1;//aumenta en 1 contando los nodos
        i = i->sgte;//recorre la cola
   }
   return contador; 
}
int estaVacia(cola **inicio){
    if(*inicio == NULL){
        return 1;
    }
    return 0;
    
}
int frente(cola *inicio){
    return inicio->dato;
}
void mostrarCola(cola *inicio, cola *final){
    cola *i = (cola*)malloc(sizeof(cola));
    i = inicio;
    printf("Tamanio = %d\n", tamanio(inicio));
    if(estaVacia(&inicio)){
        printf("La cola esta vacia.\n");
    }else{
        printf("Frente = %d\n", frente(inicio));
        while(i != final->sgte){//termina cuando i es = a null
            printf("%d\n", i->dato);
                i = i->sgte;//recorro la cola
        }
    }
    free(i);
}