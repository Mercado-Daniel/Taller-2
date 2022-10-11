//leer un archivo con fgets y mostrarlo por pantalla
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(void){
    FILE *f = fopen("archivo1.txt", "r");
    char *c;
    c = (char*)malloc(100*sizeof(char));
    assert(c != NULL);
    fgets(c,100,f);
    fputs(c, stdout);
    fclose(f);
    free(c);
}