#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tipoChar();

int main()
{
    tipoChar();
    return 0;
}

void tipoChar()
{
    char *pChar;
    pChar = (char *)malloc(sizeof(char));

    printf("Contenido del puntero: %p\n", pChar);

    *pChar= 'A';
    printf("Contenido de la variable referida por el puntero: %c\n", *pChar);
	free(pChar);
}