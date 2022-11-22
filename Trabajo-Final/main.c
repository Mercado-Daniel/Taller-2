#include "header.h"

int main(void){
    int M_Costos[VERTICES][VERTICES], i, j;
    rama *arbol;
    
    for(i = 0; i < VERTICES; i++){
        for(j = i+1; j < VERTICES; j++){
            printf("Ingrese costo de lado entre vertices %d y %d : ", i, j);
            scanf("%d", &M_Costos[i][j]);
        }
    }
    for(i = 0; i < VERTICES; i++){
        for(j = i+1; j < VERTICES; j++){
            if(M_Costos[i][j] != 0){
                inserta(i, j, M_Costos[i][j], &arbol);
            }
        }
    }
    kruskal(arbol);
    return 0;
}