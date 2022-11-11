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
    elegirLista('d', "nahuel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "adrian", &chicosBuenos, &chicosMalos);
    elegirLista('d', "yair", &chicosBuenos, &chicosMalos);
    printf("lista de malos\n");
    mostrar(chicosMalos);
    elegirLista('d', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "nahuel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "juan", &chicosBuenos, &chicosMalos);
    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);

    printf("lista de buenos\n");
    mostrar(chicosBuenos);

    printf("lista de malos\n");
    mostrar(chicosMalos);
}   

