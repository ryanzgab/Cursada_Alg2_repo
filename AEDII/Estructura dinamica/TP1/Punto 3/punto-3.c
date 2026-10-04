/*3. Una variable puntero ubicada en la dirección 0x3000 apunta a la dirección 0x3100 donde se almacena una
estructura compuesta por un int y un char. El int tiene valor 42 y el char, 'X'.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int entero;
    char caracter;
}tEstructuraComp;

void tipoStruct();

int main()
{
    tipoStruct();
    return 0;
}

void tipoStruct()
{
    tEstructuraComp *pEstructura;
    pEstructura = (tEstructuraComp*)malloc(sizeof(tEstructuraComp));

    pEstructura->entero = 42;
    pEstructura->caracter= 'X';

    printf("Contenido Apuntado: %d - %c", pEstructura->entero, pEstructura->caracter);
}
