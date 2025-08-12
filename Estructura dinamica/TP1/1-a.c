#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pChar;
int *pInt;

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

void tipoChar()
{
    char Ccosa = 'A';

    pChar = &Ccosa;

    printf("\nEl contenido de mondongo es: %d\n", * pChar);
    printf("\nLa direccion de mondongo es: %p\n",   pChar);
    printf("\nla direccion del apuntador es: %p\n", &pChar);
    printf("\n---------------------------------\n");
}