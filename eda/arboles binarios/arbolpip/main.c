#include "header.h"

int main(void){
    arbol *raiz;
    raiz = NULL;

    inserta(&raiz, 10);
    inserta(&raiz, 5);
    inserta(&raiz, 18);
    inserta(&raiz, 16);
    inserta(&raiz, 3);
    
    if(es_miembro(raiz, 5) == 1){
        printf("El elemento buscado existe en el arbol\n");
    }else{
        printf("No existe \n");
    }
    if(es_miembro(raiz, 124) == 1){
        printf("El elemento buscado existe en el arbol\n");
    }else{
        printf("No existe \n");
    }


    inserta(&raiz, 124);
    suprime(&raiz, 18);

    if(es_miembro(raiz, 18) == 1){
        printf("El elemento buscado existe en el arbol\n");
    }else{
        printf("No existe \n");
    }
    if(es_miembro(raiz, 16) == 1){
        printf("El elemento buscado existe en el arbol\n");
    }else{
        printf("No existe \n");
    }
    if(es_miembro(raiz, 5) == 1){
        printf("El elemento buscado existe en el arbol\n");
    }else{
        printf("No existe \n");
    }
    if(es_miembro(raiz, 124) == 1){
        printf("El elemento buscado existe en el arbol\n");
    }else{
        printf("No existe \n");
    }
    printf("inorder\n");
    inorder(raiz);
    printf("preorder\n");
    preorder(raiz);
    printf("postorder\n");
    postorder(raiz);

    return 0;
}