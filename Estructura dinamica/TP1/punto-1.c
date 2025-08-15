/*1. Utilizar la tabla proporcionada para representar el estado de la memoria. Completar los espacios en blanco
con la dirección de memoria o el valor correspondiente según la consigna.*/
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

/*a) Una variable puntero (apuntInt) de tipo int, ubicada en la dirección 0050, se inicializa para apuntar a la
dirección 0054. La dirección 0054 contiene el dato 10.*/
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

/*b) A un puntero de tipo char (pChar) cuya dirección es 00A0 se le asigna memoria dinámica en la dirección
00AB y se le asigna el valor 'A'.*/

void tipoChar()
{
    char Ccosa = 'A';

    pChar = &Ccosa;

    printf("\nEl contenido de mondongo es: %d\n", * pChar);
    printf("\nLa direccion de mondongo es: %p\n",   pChar);
    printf("\nla direccion del apuntador es: %p\n", &pChar);
    printf("\n---------------------------------\n");
}

/*c) A un puntero de tipo float (pFloat) que se encuentra almacenado en la posición 001A se le asigna
memoria dinámica en la dirección 00B0 y se le asigna el valor 3.14.*/

void tipoFlooat()
{
    float Fcosa = 3.14;

    pFloat = &Fcosa;

    printf("\nEl contenido de mondongo es: %d\n", * pFloat);
    printf("\nLa direccion de mondongo es: %p\n",   pFloat);
    printf("\nla direccion del apuntador es: %p\n", &pFloat);
    printf("\n---------------------------------\n");
}