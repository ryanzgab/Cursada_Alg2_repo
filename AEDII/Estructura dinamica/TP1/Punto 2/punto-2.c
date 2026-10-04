/*2. Una variable puntero a char ubicada en la dirección 0x1050 apunta a la dirección 0x1080, donde se
encuentra el string "Anastacia"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char t_String [10];

int main()
{
	
	t_String *puntero;
	
	//printf("el contenido del puntero es: %c ", *puntero);
	puntero= malloc(sizeof(t_String));

	strcpy(*puntero ,"Anastacia");
    printf("Direccion de memoria de puntero es:%p \n", &puntero);
    printf("Contenido de mi variable puntero: %p \n", puntero);
    printf("El nombre de la persona es: %s \n", *puntero);
};

/*creditos: William Abdon Alarcon*/