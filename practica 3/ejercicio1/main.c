#include "uno.h"

int main(void){
    int i, n;
    printf("Ingrese el tamaño del arreglo lista : ");
    scanf("%d", &n);
    Archivo *lista = (Archivo*)malloc(n * sizeof(Archivo));
    if(lista == NULL){
        printf("no se reservo memoria");
        exit(1);
    }

    for(i = 0; i < n; i++){
        lista[i].nombre =(char*)malloc(10*sizeof(char));
        if(lista[i].nombre == NULL){
            printf("no se reservo memoria");
            exit(1);
        }
    }
    for(i = 0; i < n; i++){
        printf("Ingrese el nombre del arcrivo %d : ", i+1);
        scanf("%s", lista[i].nombre);
        printf("Ingrese la fecha de modificacion : \n");
        printf("Hora : ");
        scanf("%d", &lista[i].ultima_mod.hora);
        printf("Minuto : ");
        scanf("%d", &lista[i].ultima_mod.minuto);
        printf("Segundos : ");
        scanf("%d", &lista[i].ultima_mod.segundo);
        printf("Dia : ");
        scanf("%d", &lista[i].ultima_mod.dia);
        printf("Mes : ");
        scanf("%d", &lista[i].ultima_mod.mes);
        printf("Anio : ");
        scanf("%d", &lista[i].ultima_mod.anio);
    }
    for(i = 0; i < n; i++){
        printf("nombre: %s \n", lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }
    printf("\n");
    ordena_temporal(lista, n);

    for(i = 0; i < n; i++){
        printf("nombre: %s \n", lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }

    printf("\n");
    ordena_alfa(lista, n);

    for(i = 0; i < n; i++){
        printf("nombre: %s \n", lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }

    for(i = 0; i < n; i++){
        free(lista[i].nombre);
    }
    free(lista);
    
}
