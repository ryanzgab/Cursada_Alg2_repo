/*a) Una variable puntero (apuntInt) de tipo int, ubicada en la dirección 0050, se inicializa para apuntar a la
dirección 0054. La dirección 0054 contiene el dato 10.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pChar;
int *pInt;
float *pFloat;

void tipoInt();
void tipoChar();

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



/*c) A un puntero de tipo float (pFloat) que se encuentra almacenado en la posición 001A se le asigna
memoria dinámica en la dirección 00B0 y se le asigna el valor 3.14.*/

void tipoFlooat()
{
    float Fcosa = 3.14;

    pFloat = &Fcosa;

    printf("\nEl contenido de mondongo es: %f\n", * pFloat);
    printf("\nLa direccion de mondongo es: %p\n",   pFloat);
    printf("\nla direccion del apuntador es: %p\n", &pFloat);
    printf("\n---------------------------------\n");
}