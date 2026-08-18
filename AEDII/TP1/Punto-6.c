/*
################################## 
#             AEDII              # 
# Trabajo Practico #1 - Punteros # 
################################## 

- #NOM. PROGRAMA: Punto-6.c
- #NOM. ALUMNO: Juan Gabriel Medina
- #DESCRIPCION: Analisis de Codigo
- #REVISION: [Ninguna]
*/

/*
-->Variable de ejemplo:
    #################
    ### char *eso ###
    #################

    a)- Es posible ejecutar a *eso = malloc(sizeof(int));
    b)- Y ejercutar eso = malloc(sizeof(int));?

    Respuesta:
        Si es posible ejecutar *eso = malloc(sizeof(int)); pero la asignacion de espacio es para un entero y no un char,
    y al utilizar un printf ya sea "eso" como "*eso"  su dato tipo puntero y algun dato de tipo char no muestra nada en pantalla.
        En cuanto a eso = malloc(sizeof(int)); tambien ejecuta, pero con la diferencia de que si muestra los datos
        como su dato de tipo puntero y un dato de tipo char "á".

        Aun asi, el asterisco es utilizado para acceder al dato de la variable referenciada por el puntero. En primera "eso" no se inizializo
        correctamente y en segunda se esta queriendo guardar la dirreccion que devulve malloc dentro del puntero de tipo char el cual no apunta a ningun lado
        por no tener ninguna direccion a la cual referirse. Y como tercer punto la asignacion de espacio de un tipo entero.

        En el segundo caso si ejecuta correctamente, porque se asigna memoria y devuelve una direccion para operar el puntero correctamente.
        Lo que si los byte van a ser distintos al ser reservado en tipo entero, pero unicamente va poder guardar datos de tipo char. No de tipo entero.
*/
/*
---> Codigo de Ejemplo:
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *eso;
    *eso=malloc(sizeof(int));

    printf("%p", eso);
    printf("\n");
    printf("%c",*eso);
    return 0;
}