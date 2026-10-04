/*
4. Dadas las siguientes declaraciones:
    typedef float Real;
    typedef Real *PunteroAReal;
    Real temperatura;
    PunteroAReal punteroTemperatura;


a). La variable "Temperatura" es de tipo Float y contiene un dato de tipo flotante o decimal.
b). Es una variable de tipo Puntero que contiene el tipo de dato Float de la variable "Temperatura" y su respectiva direccion de memoria.
c). Si a continuación se ejecuta este código:*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float temperatura;
    float *punteroTemperatura = malloc(sizeof(float));
    *punteroTemperatura = 5.5;
    temperatura = 3.3;
    printf("Puntero Temperatura %p", punteroTemperatura);
    printf("\nDato de Puntero Temperatura* %2.f", *punteroTemperatura);
    printf("\nDato de Temperatura %2.f", temperatura);

    return 0;
}
    /*I).No, porque porq el puntero Temperatura apunta a la direccion de memoria de la variable temperatura. Mientras &temperatura apunta a la direccion de mememoria en la q se almacena 3.3´´*/


























