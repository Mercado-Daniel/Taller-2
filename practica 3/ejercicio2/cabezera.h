#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct{
    int n;
    double *coeficiente;
}Polinomio;

Polinomio *creaPolinomio(int orden);//a crea y retorna un nuevo Polinomio
void setCoef(int n, double c, Polinomio *p);//b asigna el n_esimo coeficiente del polinomio
double getCoef(int n, Polinomio *p);//c retorna el n_esimo coeficiente del polinomio
double especializa(double x, Polinomio *p);//d calcula el polinomio en x usando: ((..((c[n]*x+c[n-1])*x+c[n-2])*x+...+c[1]*x)+c[0])
Polinomio *sum(Polinomio *p1, Polinomio *p2);//e suma dos polinomios retorna un nuevo polinomio con el resultado
Polinomio *mult(Polinomio *p1, Polinomio *p2);//f multiplica dos polinomios y retorna un nuevo polinomio con el resultado
