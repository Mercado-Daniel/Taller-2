#include "cabezera.h"

Polinomio *creaPolinomio(int orden){
    Polinomio *p;
    int i;
     p = (Polinomio*)malloc(sizeof(Polinomio));
     p->n = orden;
     p->coeficiente = (double*)malloc((orden + 1)*sizeof(double));
     for(i = 0; i <= orden; i++){
        p->coeficiente[i] = rand()%10 + 1;
     }
     return p;
}

