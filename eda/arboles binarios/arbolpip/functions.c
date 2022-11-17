#include "header.h"

void inserta(arbol **A, int x){
    if(*A == NULL){
        *A = (arbol*)malloc(sizeof(arbol));
        (*A)->dato = x;
        (*A)->h_izq = NULL;
        (*A)->h_der = NULL;
    }else{
        if(x < (*A)->dato){
            inserta(&((*A)->h_izq), x);
        }else if(x > (*A)->dato){
            inserta(&((*A)->h_der), x);
        }
    }
}

int es_miembro(arbol *A, int x){
    if(A == NULL){
        return -1;
    }else if(A->dato == x){
        return 1;
    }else if(A->dato > x){
        return es_miembro(A->h_izq, x);
    }else{
        return es_miembro(A->h_der, x);
    }
}

int suprime_min(arbol **A){
    int v_ref;
    if((*A)->h_izq == NULL){//en caso del que no tenga hijo izquierdo
        v_ref = (*A)->dato;//guardo el dato en v_ref
        arbol *tmp = *A;//igualo el arbol a un temporal
        *A = (*A)->h_der;//combierto el hijo derecho en el nuevo nodo
        free(tmp);
        return v_ref;
    }else{
        return suprime_min(&(*A)->h_izq);//si tiene hijo izquierdo pruevo con este
    }
}

void suprime(arbol **A, int x){
    if(*A != NULL){//busco la hoja o rama recorriendo el arbol con recursividad
        arbol *tmp = *A;//igualo tmp a el arbol para guardar la referencia del nodo  a borrar
        if(x < (*A)->dato){//si x es menor a dato me muevo a la derecha con recursividad
            suprime(&(*A)->h_izq, x);
        }else if(x > (*A)->dato){//si x es mayor a dato me muevo a la izquierda con recursividad
            suprime(&(*A)->h_der, x);
        }else if((*A)->h_izq == NULL && (*A)->h_der == NULL){//en caso de que sea un nodo sin hojas
            *A = NULL;//como no tiene ninguna hoja directamente lo igualo a null
            free(tmp);
        }else if((*A)->h_izq == NULL){// en caso de que el nodo tenga solo hoja derecha
            *A = (*A)->h_der;//conecto el padre del nodo con el hijo derecho del nodo
            free(tmp);
        }else if((*A)->h_der == NULL){// en caso de que el nodo tenga solo hoja izquierda
            *A = (*A)->h_izq;//conecto el padre del nodo con el hijo izquierda del nodo
            free(tmp);
        }else{// tiene hoja izquierda y derecha
            (*A)->dato = suprime_min(&((*A)->h_der));//llamo a suprime_min con el hijo derecho
        }
    }
}

void inorder(arbol *A){
    if(A->h_izq){
        inorder(A->h_izq);
    }
    printf("%d\n", A->dato);
    if(A->h_der){
        inorder(A->h_der);
    }
}

void preorder(arbol *A){
    printf("%d\n", A->dato);
    if(A->h_izq){
        preorder(A->h_izq);
    }
    if(A->h_der){
        preorder(A->h_der);
    }
}

void postorder(arbol *A){
    if(A->h_izq){
        postorder(A->h_izq);
    }
    if(A->h_der){
        postorder(A->h_der);
    }
    printf("%d\n", A->dato);
}
