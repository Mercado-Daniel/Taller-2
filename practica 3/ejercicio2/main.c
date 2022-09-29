#include "cabezera.h"

int main(void){
    srand(getpid());
    int n = 10;
    Polinomio *poli1;

     poli1 = creaPolinomio(n);

     for(int i = 0; i <= n; i++){
        printf("%f\n", poli1->coeficiente[i]);
     }

}