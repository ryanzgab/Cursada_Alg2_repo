#include <stdio.h>
/* ASIGNACION ESTATICA */

/*
Estructuras de datos estudiadase almacenan estáticamente en la memoria física del computador. ​
Esta rigidez  en las  estructuras de datos estáticas hace que no pueden crecer o menguar durante la ejecución de un programa.​
La representación de ciertas construcciones (como las listas) usando las estructuras conocidas (arrays) tiene que hacerse situando elementos consecutivos en componentes contiguas, 
de manera que las operaciones de inserción de un elemento nuevo o desaparición de uno ya existente requieren el desplazamiento de todos los posteriores para cubrir el vacío producido, 
o para abrir espacio para el nuevo.​
​*/


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
