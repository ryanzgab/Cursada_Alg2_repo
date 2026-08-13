/*
 ███  █████ ████  ███ ███            ████  █   █ █   █ █████ █████ ████   ███   ████ 
█   █ █     █   █  █   █             █   █ █   █ ██  █   █   █     █   █ █   █ █     
█████ ████  █   █  █   █     ████    ████  █   █ █ █ █   █   ████  ████  █   █  ███  
█   █ █     █   █  █   █             █     █   █ █  ██   █   █     █  █  █   █     █ 
█   █ █████ ████  ███ ███            █      ███  █   █   █   █████ █   █  ███  ████  
*/

/*
- NOM. PROGRAMA: Punto-2.c
- NOM. ALUMNO: Medina Juan Gabriel
- DESCRIPCION: Programa capaz de mostrar, atravez de una impresion de pantalla la direccion de memoria de una variable de 
tipo string, como tambien la direccion del puntero, a la que apunta. Y por ultimo su contenido apuntado. 
- REVISION: [NINGUNA]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char t_String [10];

void casoA();
void casoB();


int main()
{
	casoA();
    casoB();

    return 0;
};

void casoA()
{
	t_String *puntero;
	
	puntero= malloc(sizeof(t_String)); /*Asignacion de memoria*/

	strcpy(*puntero ,"Anastacia");
    printf("[CASO PRINCIPAL]\n");
    printf("Direccion de memoria de puntero es:%p \n", &puntero);
    printf("Contenido de mi variable puntero: %p \n", puntero);
    printf("El nombre de la persona es: %s \n", *puntero);
    printf("\n");
}

void casoB() /*Se remite un caso secundario indicado en la actividad de quitar el malloc y tipearlo de otra forma*/
{
	t_String *puntero = "Anastacia"; /*NOTA: En mi caso, sale una advertencia de que la inicializacion es incompatible...*/
	
    /*... aun asi el programa funciona igualmente*/
    printf("[CASO SECUNDARIO]\n");
    printf("Direccion de memoria de puntero es:%p \n", &puntero);
    printf("Contenido de mi variable puntero: %p \n", puntero);
    printf("El nombre de la persona es: %s \n", *puntero);

}    
