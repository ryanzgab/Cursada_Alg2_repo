#include <stdio.h>
/* ASIGNACIÓN ESTÁTICA */

/* Declaración de tipos de datos personalizados */

/* Declaración de prototipos de funciones */
void ejPunteroFloat();

/* Declaración de variables globales */


/* Función principal */
int main() {
	ejPunteroFloat();
	return 0;
}

/* Implemetación de funciones */
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
