#include "cabezera.h"

int main(void){
    srand(getpid());
    int n = 10;
    Polinomio *poli;

     poli = creaPolinomio(n);

     for(int i = 0; i <= n; i++){
        printf("%f\n", poli->coeficiente[i]);
     }

}