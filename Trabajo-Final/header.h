#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VERTICES 5

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

typedef struct _Arista{
    vertice u;
    vertice v;
    int costo;
}arista;

typedef struct _Rama{
    struct _Arista a;
    struct _Rama *sig;
}rama;

typedef struct _Encabezado{
    int cuenta;
    int primer_elemento;
}encabezado;

typedef struct _Nombre{
    tipo_nombre nombre_conjunto;
    int siguiente_elemento;
}nombre;

typedef struct _Conjunto_Ce{
    nombre nombres[VERTICES];
    encabezado encabezamientos_conjunto[VERTICES];
}conjuntoCe;

void inicial(tipo_nombre, tipo_elemento, conjuntoCe *);
void combina(tipo_nombre, tipo_nombre, conjuntoCe);
tipo_nombre encuentra(int, conjuntoCe*);
void kruskal(rama *);

void inserta(int, int, int, rama **);
arista* sacar_min(rama **);
void lista(rama *);