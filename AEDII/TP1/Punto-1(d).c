/*
################################## 
#             AEDII              # 
# Trabajo Practico #1 - Punteros # 
################################## 

- #NOM. PROGRAMA: Punto-1-(d).c
- #NOM. ALUMNO: Medina Juan Gabriel
- #DESCRIPCION: Programa que pone en practica los items anteriores, con el añadido del (Malloc) asignacion de memoria por cada
tipo de dato. De los puntos: A, B, C.
- #REVISION: [NINGUNA]
*/
#include <stdio.h>
#include <stdlib.h>


void casoA();
void casoB();
void casoC();


int main()
{   
    casoA();
    casoB();
    casoC();
    return 0;
}

void casoA()
{
    int* ApInt;
    ApInt = malloc(sizeof(int)); /*Asignacion de memoria*/


    printf("Contenido del puntero: %p\n", ApInt);

    *ApInt= 10;
    printf("Contenido de la variable referida por el puntero: %d\n", *ApInt);
	free(ApInt);
    printf("\n");
}

void casoB()
{
    char* ApChar;
    ApChar = malloc(sizeof(char)); /*Asignacion de memoria*/

    printf("Contenido del puntero: %p\n", ApChar);

    *ApChar= 'A';
    printf("Contenido de la variable referida por el puntero: %c\n", *ApChar);
	free(ApChar);
    printf("\n");
}

void casoC()
{
    float* ApFloat;
    ApFloat = malloc(sizeof(float)); /*Asignacion de memoria*/

    printf("Contenido del puntero: %p\n", ApFloat);

    *ApFloat= 3.14;
    printf("Contenido de la variable referida por el puntero: %.2f\n", *ApFloat);
	free(ApFloat);
    printf("\n");
}