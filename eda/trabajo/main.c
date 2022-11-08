#include "header.h"

int main(void){
    politico *chicosBuenos, *chicosMalos;
    chicosBuenos = NULL;
    chicosMalos = NULL;

    elegirLIsta('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "jose", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "alejandro", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "juan", &chicosBuenos, &chicosMalos);
    printf("lista de buenos\n");
    mostrar(chicosBuenos);
    elegirLIsta('d', "samael", &chicosBuenos, &chicosMalos);
    elegirLIsta('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLIsta('d', "abel", &chicosBuenos, &chicosMalos);
    elegirLIsta('d', "jafer", &chicosBuenos, &chicosMalos);
    printf("lista de malos\n");
    mostrar(chicosMalos);
    elegirLIsta('d', "daniel", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLIsta('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLIsta('d', "samael", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "juan", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLIsta('f', "daniel", &chicosBuenos, &chicosMalos);

    printf("lista de buenos\n");
    mostrar(chicosBuenos);

    printf("lista de malos\n");
    mostrar(chicosMalos);
}   

