/*
 ███  █████ ████  ███ ███            ████  █   █ █   █ █████ █████ ████   ███   ████ 
█   █ █     █   █  █   █             █   █ █   █ ██  █   █   █     █   █ █   █ █     
█████ ████  █   █  █   █     ████    ████  █   █ █ █ █   █   ████  ████  █   █  ███  
█   █ █     █   █  █   █             █     █   █ █  ██   █   █     █  █  █   █     █ 
█   █ █████ ████  ███ ███            █      ███  █   █   █   █████ █   █  ███  ████  
*/

/*
- NOM. PROGRAMA: Punto-3.c
- NOM. ALUMNO: Medina Juan Gabriel
- DESCRIPCION: Programa con una similitud con el punto anterior pero en cambio, se maneja con una estructura de int 
y char. Con el agregado de un puntero adicional que apunte a la estructura y la modifica en cada campo.
- REVISION: [NINGUNA]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int entero;
    char caracter;
}tDatos;

int main()
{
    tDatos* pDatos;
    tDatos* pDatos2;
    pDatos=(tDatos*)malloc(sizeof(tDatos));
    pDatos2=(tDatos*)malloc(sizeof(tDatos));


    pDatos->caracter= 'X';
    pDatos->entero= 42;

    printf("[Primer Caso]\n");
    printf("Datos de punteros: %d - %c\n", pDatos->entero, pDatos->caracter);
    system("pause");

    pDatos2= pDatos;
    pDatos2->entero= 100;

    printf("[Segundo Caso]\n");
    printf("Datos de punteros: %d - %c\n", pDatos2->entero, pDatos2->caracter);
    
    return 0;
}
