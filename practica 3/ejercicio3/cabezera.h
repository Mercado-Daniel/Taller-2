#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char sign;
    unsigned char num_bytes;
    unsigned char *bytes;
}Apint;

Apint *suma_Apint(Apint *i1, Apint *i2);//a
Apint *producto_Apint(Apint *i1, Apint *i2);//b

