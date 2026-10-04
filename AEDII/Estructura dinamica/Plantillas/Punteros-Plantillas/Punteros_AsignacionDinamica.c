#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCAD 25

/* ASIGNACI�N DIN�MICA */

/* Declaraci�n de tipos de datos personalizados */
typedef char tString[MAXCAD];

typedef struct {
	int LU;
	tString apellido;
	tString nombre;
}tEstudiante;

/* Declaraci�n de prototipos de funciones */
void ejPunteroFloat();
void ejPunteroChar();
void ejPunteroStruct();

/* Declaraci�n de variables globales */


/* Funci�n principal */
int main() {
	ejPunteroStruct();
	// ejPunteroChar();
	// ejPunteroFloat();
	return 0;
}

/* Implemetaci�n de funciones */
void ejPunteroFloat() {
	// Se declara la variable puntero
	float * apValorReal;
	
	apValorReal = (float *) malloc( sizeof(float) );
	
	printf("Contenido del puntero: %p\n", apValorReal);
	
	*apValorReal = 1500.25;
	
	printf("Contenido de la variable referida por el puntero: %.2f\n", *apValorReal);
	free(apValorReal);
}

void ejPunteroChar() {
	char * eso;
	
	// eso =  malloc(sizeof(int));
	eso = (char *) malloc(sizeof(char));	
	*eso = '+';
	
	printf("Contenido de la variable referida por el puntero: %c\n", *eso);
	
	printf("Valor del puntero: %p", eso);	
}

void ejPunteroStruct() {
	tEstudiante * apEstudiante;
	
	apEstudiante = (tEstudiante * ) malloc(sizeof(tEstudiante));
	
	(*apEstudiante).LU = 234567;
	strcpy((*apEstudiante).apellido, "Gomez");
	apEstudiante->LU = 5789;
	strcpy(apEstudiante->nombre, "Luis");
	
	printf("Estudiante: %d-%s, %s",
			apEstudiante->LU,
			apEstudiante->apellido,
			apEstudiante->nombre );
}




/*Las direcciones de memoria se pueden escribir de distintas formas, pero todas representan valores numéricos que
indican ubicaciones en la memoria RAM. Algunas formas comunes de representarlas:
0050, 001A, 0125: Son números en base 16 (hexadecimal), pero sin el prefijo.
0x4000: Es la forma estándar en C para escribir un número en hexadecimal. El prefijo 0x indica que el valor está en
base 16.
Las direcciones que se imprimen con %p en la consola como 0x7ffeeaa30458, representan direcciones reales en la
computadora al ejecutar el programa.
¿Por qué utilizar el sistemas hexadecimal? Porque es una forma más compacta y legible de representar direcciones
binarias. Cada dígito hexadecimal representa 4 bits.*/
