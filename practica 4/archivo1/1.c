#include<stdio.h>
#include<stdlib.h>
//leer un arcrhivo con fgetc y mostrarlo por pantalla
int main(void){
    FILE *f = fopen("archivo1.txt", "r");
    int c; 
    while ((c = fgetc(f)) != -1){
       fputc(c, stdout);
    }
    fclose(f);
}