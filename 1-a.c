#include <stdio.h>

#define N 4

void cargarMatriz(int matriz[N][N]);

int main(void)
{
    int matriz[N][N];
    cargarMatriz(matriz);
    return 0;
}

void cargarMatriz(int matriz[][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        printf("[ ");
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
            printf("%d ", matriz[i][j]);
        }
        printf("]\n");
    }
}