#include <stdio.h>
/* ASIGNACI�N EST�TICA */

/* Declaraci�n de tipos de datos personalizados */

/* Declaraci�n de prototipos de funciones */
void ejPunteroFloat();

/* Declaraci�n de variables globales */


/* Funci�n principal */
int main() {
	ejPunteroFloat();
	return 0;
}

/* Implemetaci�n de funciones */
void ejPunteroFloat() {
	float nroReal = 10;
	
	float * apFloat;
	
	apFloat = &nroReal;
	
	nroReal = nroReal * 2;
	
	*apFloat = *apFloat * 100;
	
	printf("El contenido de nroReal: %.2f\n", nroReal);
	printf("El contenido de *apFloat: %.2f\n", *apFloat);
	
	printf("La direccion de nroReal: %p\n", &nroReal);
	printf("La direccion de nroReal a traves del puntero: %p\n", apFloat);
	
	printf("La direccion de la variable puntero: %p\n", &apFloat);
	
}
