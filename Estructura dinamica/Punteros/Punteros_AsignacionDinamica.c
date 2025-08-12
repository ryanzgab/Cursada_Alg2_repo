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

