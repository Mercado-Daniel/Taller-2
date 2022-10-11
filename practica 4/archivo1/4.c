//leer un archivocon fgets y crear uno nuevo con con el mismo contenido usando fputs
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(void){
    FILE *f1 = fopen("archivo1.txt", "r");
    FILE *f2 = fopen("archivo4.txt", "w");
    char *c;
    c = (char*)malloc(100 * sizeof(char));
    assert(c != NULL);
    fgets(c, 100, f1);
    fputs(c, f2);
    fclose(f1);
    fclose(f2);
    free(c);
}