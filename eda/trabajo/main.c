#include "header.h"

int main(void){
    politico *chicosBuenos, *chicosMalos;
    chicosBuenos = NULL;
    chicosMalos = NULL;

    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "jose", &chicosBuenos, &chicosMalos);
    elegirLista('f', "alejandro", &chicosBuenos, &chicosMalos);
    elegirLista('f', "juan", &chicosBuenos, &chicosMalos);
    printf("lista de buenos\n");
    mostrar(chicosBuenos);
    elegirLista('d', "samael", &chicosBuenos, &chicosMalos);
    elegirLista('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "abel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "jafer", &chicosBuenos, &chicosMalos);
    printf("lista de malos\n");
    mostrar(chicosMalos);
    elegirLista('d', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "samael", &chicosBuenos, &chicosMalos);
    elegirLista('f', "juan", &chicosBuenos, &chicosMalos);
    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);

    printf("lista de buenos\n");
    mostrar(chicosBuenos);

    printf("lista de malos\n");
    mostrar(chicosMalos);
}   

