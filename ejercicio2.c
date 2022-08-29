#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 4

void cargarNotas(float notas[][N]);
void sumarFilas(float notas[][N], float sumaF[]);
void sumarColumnas(float notas[][N], float sumaC[]);
void promedioAlumno(float suma[], float promedio []);
void mostrar(float notas[][N], float promedioA[], float promedioM[]);

int main(void){
    srand(getpid());
    float notas[N][N];
    float sumaF[N];
    float sumaC[N];
    float promedioA[N];
    float promedioM[N];
    cargarNotas(notas);
    sumarFilas(notas, sumaF);
    sumarColumnas(notas, sumaC);
    promedioAlumno(sumaF, promedioA);
    promedioAlumno(sumaC, promedioM);
    mostrar(notas, promedioA, promedioM);

    return 0;
}

void cargarNotas(float notas[][N]){
    int i, j;

    for(i = 0; i < N; i++){
        for (j= 0; j < N; j++){
            notas[i][j] = (rand()%1100)/100.0f;
        }
    }
}

void sumarFilas(float notas[][N],float sumaF[]){
    int i, j;
    for(i = 0; i < N; i++){
        sumaF[i] = 0;
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            sumaF[i] += notas[i][j];
        }
    }

}

void sumarColumnas(float notas[][N],float sumaC[]){
    int i, j;
    for(i = 0; i < N; i++){
        sumaC[i] = 0;
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            sumaC[i] += notas[j][i];
        }
    }

}

void promedioAlumno(float suma[], float promedio[] ){
    int i;
    for(i = 0; i < N; i++){
        promedio[i] = (suma[i] /N);
    }
}


void mostrar(float notas[][N], float promedioA[], float promedioM[]){
    int i, j;
    for(i = 0; i < N; i++){
        printf("[ ");
        for(j = 0; j < N; j++){
            printf("%.2f ",notas[i][j]);
        }
        if(promedioA[i] >= 8.00){
            printf("] => [ %.2f ] Promovido\n", promedioA[i]);
        }else if(promedioA[i] >= 6.00){
            printf("] => [ %.2f ] Regular\n", promedioA[i]);
        }else{
            printf("] => [ %.2f ] Libre\n", promedioA[i]);
        }
    }
    printf("\n");
    for(i = 0; i < N; i++){
        printf("[%.2f]", promedioM[i]);
    }
    printf("\n");
}