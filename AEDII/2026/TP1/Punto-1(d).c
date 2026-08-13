/*
 ███  █████ ████  ███ ███            ████  █   █ █   █ █████ █████ ████   ███   ████ 
█   █ █     █   █  █   █             █   █ █   █ ██  █   █   █     █   █ █   █ █     
█████ ████  █   █  █   █     ████    ████  █   █ █ █ █   █   ████  ████  █   █  ███  
█   █ █     █   █  █   █             █     █   █ █  ██   █   █     █  █  █   █     █ 
█   █ █████ ████  ███ ███            █      ███  █   █   █   █████ █   █  ███  ████  
*/

/*
- NOM. PROGRAMA: Punto-1-(d).c
- NOM. ALUMNO: Medina Juan Gabriel
- DESCRIPCION: Escribir un programa en C que implemente las situaciones anteriores, mostrando en la consola las direcciones de memoria y los valores del dato antes y después 
de la modificación de cada una de las variables que intervienen. Utilizar asignación estática y dinámica (malloc). 
- REVISION: [NINGUNA]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int data;
char caracter;
float flotante;

void casoA();
void casoB();
void casoC();


int main()
{
    casoB();
    return 0;
}

void casoA()
{
    int* ApData;
    ApData = (int*)malloc(sizeof(int)); /*Asignacion de memoria*/

    data = 10;
    ApData = &data;


    printf("Direccion de memoria de puntero es:%p \n", &ApData);
    printf("Contenido de mi variable puntero: %p \n", ApData);
    printf("Direccion de la Variable Data: %p\n", &data);
    printf("El valor entero es: %d \n", *ApData);
}

void casoB()
{
    char* ApData;
    ApData = (char*)malloc(sizeof(char)); /*Asignacion de memoria*/

    caracter = 'A';
    ApData = &caracter;


    printf("Direccion de memoria de puntero es:%p \n", &ApData);
    printf("Contenido de mi variable puntero: %p \n", ApData);
    printf("Direccion de la Variable Data: %p\n", &caracter);
    printf("El valor entero es: %c \n", *ApData);
}

void casoC()
{
    float* ApData;
    ApData = (float*)malloc(sizeof(float)); /*Asignacion de memoria*/

    flotante = 'A';
    ApData = &;


    printf("Direccion de memoria de puntero es:%p \n", &ApData);
    printf("Contenido de mi variable puntero: %p \n", ApData);
    printf("Direccion de la Variable Data: %p\n", &caracter);
    printf("El valor entero es: %c \n", *ApData);
}