#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCAR 25

/* Declaración de tipos de datos personalizados */
typedef char tString[MAXCAR];

typedef struct{
	int codigo;
	tString nombre;
}tColor;

typedef struct nodoColor {
	tColor color;
	struct nodoColor * siguiente;
}tListaColores;

/* Declaración de prototipos de funciones */

void inicializarLista();
bool listaVacia(tListaColores *);
void insertarColor(tColor);
void insertarPrimerColor(tColor);
void insertarColorAdelante(tColor);
void eliminarPrimerColor();
void mostrarColores(tListaColores *);
int contarColores(tListaColores *);

void insertaColorEnPos(int, tColor);
void eliminarColorDePos(int);

void menu();

/* Declaración de variables globales */
tListaColores * listaColores;

/* Función principal */
int main() {
	
	inicializarLista();
	
	menu();
	
	return 0;
}

/* Implementación de funciones */
void inicializarLista() {
	/* Simplemente la lista tiene que apuntar NULL */
	listaColores = NULL;
	printf("Lista de colores inicializada!\n");
}

bool listaVacia(tListaColores * pListaColores) {
	/* 	Devuelve true en el caso que la lista apunte a NULL 
		y false en caso contrario*/		
	return (pListaColores == NULL);
}

void insertarColor(tColor pColor) {
	if(listaVacia(listaColores)){
		insertarPrimerColor(pColor);
	}else{
		insertarColorAdelante(pColor);
	}
}

void insertarPrimerColor(tColor pColor) {
	/* Crear el nodo que se va a insertar */
	tListaColores * nuevoColor;
	
	/* Reservar y asignar memoria al nuevo nodo */
	nuevoColor = (tListaColores *) malloc(sizeof(tListaColores));
	
	/* Asignar el valor recibido al componente correspondiente al contenido */
	nuevoColor->color = pColor;
	
	/* Indicar que el primer nodo apunta a NULL */
	nuevoColor->siguiente = NULL;
	
	/* La lista debe apuntar al nuevo nodo */
	listaColores = nuevoColor;
	
	printf("\nPrimer color insertado: %s", pColor.nombre);
}

void insertarColorAdelante(tColor pColor) {
	/* Crear el nodo que se va a insertar */
	tListaColores * nuevoColor;
	
	/* Reservar y asignar memoria al nuevo nodo */
	nuevoColor = (tListaColores *) malloc(sizeof(tListaColores));
	
	/* Asignar el valor recibido al componente correspondiente al contenido */
	nuevoColor->color = pColor;
	
	/* Como se inserta por adelante, indicar que al nuevoNodo le sigue la lista */
	nuevoColor->siguiente = listaColores;
	
	/* La lista debe apuntar al nuevo nodo */
	listaColores = nuevoColor;
	
	printf("\nColor insertado: %s", pColor.nombre);
}

void eliminarPrimerColor() {
	if(listaVacia(listaColores)){
		printf("No hay colores para quitar de la lista!\n");
	}else{
		
		/* Almacenar el nodo a suprimir en una variable auxiliar */		
		tListaColores * colorSuprimir = listaColores;
		
		/* Romper el enlace al primer elemento */
		listaColores = listaColores->siguiente;
		
		/* Imprimir un mensaje representativo */
		printf("\nColor quitado: %s", colorSuprimir->color.nombre);
		
		/* Liberar la memoria del nodo suprimido */
		free(colorSuprimir);		
		colorSuprimir = NULL;		
	}
}

void mostrarColores(tListaColores * pListaColores) {
	if(listaVacia(pListaColores)){
		printf("No hay colores para mostrar en la lista!\n");
	}else{
		tListaColores * listaAux = pListaColores;
		printf("\n *** Lista de colores ***\n");
		while(listaAux != NULL){
			printf("%d-%s | ", 
					listaAux->color.codigo,
					listaAux->color.nombre);
			listaAux = listaAux->siguiente;
		}	
	}
}

int contarColores(tListaColores * pListaColores) {
	if(listaVacia(pListaColores)){
		return 0;
	}else{
		tListaColores * listaAux = pListaColores;
		int cantidadColores = 0;
		while(listaAux != NULL){
			cantidadColores++;
			listaAux = listaAux->siguiente;
		}
		return cantidadColores;
	}
}

void insertaColorEnPos(int posicion, tColor pColor) {
	/* Se debe utilizar una lista auxiliar (aux) */
	tListaColores * listaAux = listaColores;
	
	/* 	Avanzar hasta el nodo anterior a la posición 
		donde se quiere insertar */
	int i;
	for(i = 1; i < posicion-1; i++) {
		listaAux = listaAux->siguiente;
	}
	
	/* Reservar memoria para el nodo que se va a insertar */
	tListaColores * nuevoNodo = (tListaColores *) malloc(sizeof(tListaColores));
	
	/* Asignar valor a la componente del dato */
	nuevoNodo->color = pColor;
	
	/* Actualización de punteros */
	
	/* Actualizar componente puntero del nuevo nodo */
	nuevoNodo->siguiente = listaAux->siguiente;
		
	/* Actualizar componente puntero del nodo auxiliar */
	listaAux->siguiente = nuevoNodo;
	
	printf("\nColor insertado en la posicion %d: %s", 
				posicion, pColor.nombre);
}

void eliminarColorDePos(int posicion) {
	/* Se debe utilizar una lista auxiliar (aux) */
	tListaColores * listaAux = listaColores;
	
	/* 	Avanzar hasta el nodo anterior a la posición 
		donde se quiere quitar */
	int i;
	for(i = 1; i < posicion-1; i++) {
		listaAux = listaAux->siguiente;
	}
	
	/* Resguardar el nodo a suprimir */
	tListaColores * colorSuprimir = listaAux->siguiente;
	
	/* 	Actualizar el puntero siguiente del nodo anterior 
		al que se va a quitar */
	listaAux->siguiente = colorSuprimir->siguiente;
	
	printf("\nColor quitado de la posicion %d: %s", 
			posicion,
			colorSuprimir->color.nombre);
	
	/* Liberar la memoria del puntero color a suprimir */	
	free(colorSuprimir);
	colorSuprimir = NULL;
}

void menu() {
	char opcion;
	
	printf("\nSeleccione una opcion:\n\ti-Insertar\tq-quitar ");
	printf("\n\tp-Insertar en pos\tr-quitar de pos  ");
	printf("\n\tv-visualizar\ts-salir:  ");	
	fflush(stdin);
	scanf("%c", &opcion);
	
	opcion = tolower(opcion);
	
	switch(opcion) {
		case 'i':  {			
						tColor color;
						printf("Ingrese codigo: ");
						scanf("%d", &color.codigo);
						printf("Ingrese nombre: ");
						fflush(stdin);
						gets(color.nombre);
						
						insertarColor(color);
						
						menu();
						
						break;
		}
		case 'q': {
					eliminarPrimerColor();
					menu();
					break;
		}		
		case 'v': 	{ 
						mostrarColores(listaColores);
						menu();	
						break;
		}
		case 'p': {
					int posicion;
					printf("Ingrese posicion: ");
					scanf("%d", &posicion);
					
					tColor color;
					printf("Ingrese codigo: ");
					scanf("%d", &color.codigo);
					printf("Ingrese nombre: ");
					fflush(stdin);
					gets(color.nombre);
					
					insertaColorEnPos(posicion, color);
					
					menu();
					
					break;
		}	
		case 'r': {
					int posicion;
					printf("Ingrese posicion: ");
					scanf("%d", &posicion);
					
					eliminarColorDePos(posicion);
					
					menu();
					
					break;
		}			
		case 's': 	printf("Salir\n");
					break;
	}
	
	
}

