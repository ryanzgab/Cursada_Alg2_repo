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
    float *pFloat;
    pFloat = (float *)malloc(sizeof(float));

    printf("Contenido del puntero: %p\n", pFloat);

    *pFloat= 3.14;
    printf("Contenido de la variable referida por el puntero: %.2f\n", *pFloat);
	free(pFloat);
}