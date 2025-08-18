#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tipoFloat();

int main()
{
    tipoFloat();
    return 0;
}

void tipoFloat()
{
    Float *pFloat;
    pFloat = (Float *)malloc(sizeof(Float));

    printf("Contenido del puntero: %p\n", pChar);

    *pChar= 'A';
    printf("Contenido de la variable referida por el puntero: %c\n", *pChar);
	free(pChar);
}