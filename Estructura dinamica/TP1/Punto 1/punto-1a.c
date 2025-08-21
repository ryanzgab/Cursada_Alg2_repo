/*a) Una variable puntero (apuntInt) de tipo int, ubicada en la dirección 0050, se inicializa para apuntar a la
dirección 0054. La dirección 0054 contiene el dato 10.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *pInt;

void tipoInt();

int main()
{
    tipoInt();
    tipoChar();
    return 0;
}

void tipoInt()
{
    int intCosa = 10;
    pInt = &intCosa;


    printf("\nEl contenido de mondongo es: %d\n", *pInt);
    printf("\nLa direccion de mondongo es: %p\n",  pInt);
    printf("\nla direccion del apuntador es: %p\n", &pInt);
    printf("\n---------------------------------\n");

    *pInt = 20;

    printf("\nEl contenido de mondongo es: %d\n", *pInt);
    printf("\nLa direccion de mondongo es: %p\n",  pInt);
    printf("\nla direccion del apuntador es: %p\n", &pInt);
    printf("\n---------------------------------\n");    
}
