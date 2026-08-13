#include <stdio.h>
#include <stdlib.h>

void pruebaA();

int * apuntInt;

int main(){
    pruebaA();
    return 0;
}

void pruebaA(){
    int mondongo;
    mondongo = 7350;

    apuntInt = &mondongo;

    printf("\nEl contenido de mondongo es: %d\n", *apuntInt);
    printf("\nLa direccion de mondongo es: %p\n", apuntInt);
    printf("\nla direccion del apuntador es: %p\n", &apuntInt);
}