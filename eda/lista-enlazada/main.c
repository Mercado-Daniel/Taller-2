#include "cabecera.h"

int main(void){
    lista *inicio;
    inicio = NULL;

    insertar(5, &inicio);
    insertar(3, &inicio);
    insertar(4, &inicio);
    insertar(10, &inicio);
    insertar(6, &inicio);
    insertar(8, &inicio);
    insertar(1, &inicio);
    insertar(8, &inicio);
    insertar(1, &inicio);

    printf("Listo elementos\n");
    listar(inicio);
    printf("Fin del listado\n");

    eliminar(4, &inicio);
    eliminar(1, &inicio);
    eliminar(10, &inicio);
    eliminar(14, &inicio);

    printf("Listo elementos\n");
    listar(inicio);
    printf("Fin del listado\n");

    return 0;
}