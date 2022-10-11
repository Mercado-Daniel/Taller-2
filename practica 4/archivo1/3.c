//leer un archivocon fgetc y crear uno nuevo con con el mismo contenido usando fputc
#include<stdio.h>

int main (void){
    FILE *f1 = fopen("archivo1.txt", "r");
    FILE *f2 = fopen("archivo3.txt", "w");
    int c;
    while((c = fgetc(f1)) != -1){
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);

}