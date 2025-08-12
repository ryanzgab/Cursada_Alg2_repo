#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXCAD 25

typedef char tString[MAXCAD];

typedef struct{
	int LU;
	tString apellido;
	tString nombre;
}tEstudiante;

int opciones;


void menuPrincipal_items();
void itemB();
void itemC();
void itemD();
void itemE();

int main(){
	menuPrincipal_items();
	return 0;
}

void menuPrincipal_items(){
	do {		//Usar "Do" para repetir el menu.
	
	system("cls");
	
	//Titulo
	printf("\t----MENU DE ITEMS TP1----\n\n");
	
	//Como utilizar el menu
	printf("\tELIJA ITEM A REVISAR\n");
	
	//Opciones de aulas
	printf("\t\-.itemA (utilizado de ejemplo en el tp)\n");
	printf("\t\t1.itemB\n");
	printf("\t\t2.itemC\n");
	printf("\t\t3.itemD\n");
	printf("\t\t4.itemE\n");
	printf("\nOpcion:");
	scanf("%d", &opciones);
	
	//Selector
	switch(opciones){
		case 1:
			itemB();
			break;
		
		case 2:
			itemC();
			break;
		
		case 3:
			itemD();
			break;
		
		case 4:
			itemE();
			break;
	
	}
	
	} while(opciones == 0);
	
}
void itemB(){
	float * apValorReal;
	apValorReal = (float *) malloc( sizeof(float) );
	printf("Contenido del puntero: %p\n", apValorReal);
	
	*apValorReal = 20.5;
	
	printf("Contenido de la variable referida por el puntero: %.2f\n", *apValorReal);
	free(apValorReal);
}

void itemC(){
	tEstudiante * apEstudiante;
	
	apEstudiante = (tEstudiante * ) malloc(sizeof(tEstudiante));
	
	
	strcpy((*apEstudiante).apellido, "True");
	
	printf("Contenido de la variable referida por el puntero: %s\n",
			apEstudiante->apellido);
	printf("Valor del puntero: %p", apEstudiante->apellido);
}

void itemD(){
	int * eso;
	
	eso =  malloc(sizeof(int));	
	*eso = 7350;
	
	printf("Contenido de la variable referida por el puntero: %d\n", *eso);
	
	printf("Valor del puntero: %p", eso);	
}

void itemE(){
	char * eso;
	
	eso = (char *) malloc(sizeof(char));	
	*eso = 'z';
	
	printf("Contenido de la variable referida por el puntero: %c\n", *eso);
	
	printf("Valor del puntero: %p", eso);	
}
