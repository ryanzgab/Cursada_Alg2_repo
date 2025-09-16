#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef char tString[MAX];

typedef struct{
	int campoInt;
	tString campoString;
	float campoFloat;
}tInfo;

typedef struct nodo{
	tInfo dato;
	struct nodo* siguiente;
}tLista;

void inicializarLista(tLista**);
bool listaVacia(tLista*);

void insertarElemento(tLista**, tInfo);
void insertarPrimerElemento(tLista**, tInfo);
void insertarElementoAlPrincipio(tLista**, tInfo);

void eliminarPrimerElemento(tLista**);

void mostrarDatosNodo(tLista*);
void mostrarDatosNodo2(tInfo);
void visualizarElementos(tLista*);     
int buscarPorID(tLista*, int);
int totalElementos(tLista*);

void liberarTodaLaMemoria(tLista**);

void menu();

tInfo cargarDatos();

int main() {

    tLista* lista;

    int opcion;
	int id;
	int posicion;

    tInfo dato;
    
    inicializarLista(&lista);
    
    //agrego un elemento
	dato.campoInt=1;
    strcpy(dato.campoString,"elem1");
    dato.campoFloat=10.5;
    insertarElemento(&lista, dato);
    
    //agrego un elemento
	dato.campoInt=2;
    strcpy(dato.campoString,"elem2");
    dato.campoFloat=20.5;
    insertarElemento(&lista, dato);
  	
	//agrego un elemento
	dato.campoInt=3;
 	strcpy(dato.campoString,"elem3");
    dato.campoFloat=30.5;
    insertarElemento(&lista, dato);
 
	visualizarElementos(lista);

    eliminarPrimerElemento(&lista);

	visualizarElementos(lista);
  
    printf("ID a buscar: ");
    scanf("%d", &id);
    posicion = buscarPorID(lista, id);
    if (posicion != -1) {
        printf("Elemento encontrado en posicion: %d\n", posicion);
    } else {
        printf("Elemento no encontrado.\n");
    }

    if (listaVacia(lista)) {
        printf("La lista esta vacia.\n");
    } else {
        printf("La lista contiene %d elementos.\n", totalElementos(lista));
    }

    liberarTodaLaMemoria(&lista);

  	printf("Fin!!.\n");

	return 0;
}

// a)	Inicializar la lista
void inicializarLista(tLista** pLista) {
	/* Simplemente la lista tiene que apuntar NULL */
	*pLista = NULL;
	
	/* Emitir un mensaje adecuado */
	printf("\tLista inicializada!\n");
}

// b)	Verificar si una lista está vacía
bool listaVacia(tLista* pLista) {
	/* 	Devuelve true en el caso que la lista apunte a NULL 
		y false en caso contrario*/		
	return (pLista == NULL);
}

/* INSERCIONES */
void insertarElemento(tLista** pLista,
						tInfo pDato) {
	if(listaVacia(*pLista)){
		insertarPrimerElemento(&(*pLista), pDato);
	}else{
		insertarElementoAlPrincipio(&(*pLista), pDato);
	}
}

// c)	Insertar el primer Elemento (nodo) de la lista.
void insertarPrimerElemento(tLista** pLista,
							  tInfo pDato) {
	/* Crear el nodo que se va a insertar */
	tLista* nuevoNodo;
	
	/* Reservar y asignar memoria al nuevo nodo */
	nuevoNodo = (tLista*) malloc(sizeof(tLista));
	
	/* Asignar el valor recibido al componente correspondiente al contenido */
	nuevoNodo->dato = pDato;	
	//(*nuevoNodo).dato = pDato;
	
	/* Indicar que el primer nodo apunta a NULL */
	nuevoNodo->siguiente = NULL;
	
	/* La lista debe apuntar al nuevo nodo */
	*pLista = nuevoNodo;
	
	/* Emitir un mensaje adecuado */
	printf("\nSe agrego el Elemento: %s!", pDato.campoString);
}

// d)	Insertar un Elemento al principio de la lista.
void insertarElementoAlPrincipio(tLista** pLista,
							  	   tInfo pDato) {
	/* Crear el nodo que se va a insertar */
	tLista* nuevoNodo;
	
	/* Reservar y asignar memoria al nuevo nodo */
	nuevoNodo = (tLista*) malloc(sizeof(tLista));
	
	/* Asignar el valor recibido al componente correspondiente al contenido */
	nuevoNodo->dato = pDato;	
	
	/* Como se inserta por adelante, indicar que al nuevoNodo le sigue la lista */
	nuevoNodo->siguiente = *pLista;
	
	/* La lista debe apuntar al nuevo nodo */
	*pLista = nuevoNodo;
	
	/* Emitir un mensaje adecuado */
	printf("\nSe agrego el Elemento: %s!", pDato.campoString);
}

/* ELIMINACIONES */
// f)	Eliminar el primer elemento de la lista.
void eliminarPrimerElemento(tLista** pLista) {
	if(listaVacia(*pLista)){
		printf("No hay Elemento para quitar de la lista!\n");
	}else{
		
		/* Almacenar el nodo a suprimir en una variable auxiliar */		
		tLista* elementoSuprimir = *pLista;
		
		/* Romper el enlace al primer elemento */
		*pLista = (*pLista)->siguiente;
		
		/* Imprimir un mensaje representativo */
		printf("\nElemento quitado: %s", elementoSuprimir->dato.campoString);
		
		/* Liberar la memoria del nodo suprimido */
		free(elementoSuprimir);		
		elementoSuprimir = NULL;		
	}
}

// h)	Buscar un Elemento por campoInt y retornar su posición.
int buscarPorID(tLista* pLista, int pNro) {
    tLista* listaAux = pLista;
    int posicion = 0;
    int elemEncontrado=-1;
    
    while (listaAux != NULL && posicion!=-1) {
    	posicion++;
        if (listaAux->dato.campoInt == pNro) {
            elemEncontrado = posicion;
        }
        listaAux = listaAux->siguiente;
    }
    
    return elemEncontrado; // si encontro retorna la posicion, en caso contrario -1
}

// i)	Visualizar todos los Elementos de la lista.
void visualizarElementos(tLista* pLista) {
	if(listaVacia(pLista)){
		printf("No hay Elementos para mostrar en la lista!\n");
		return;
	}else{
		tLista* listaAux = pLista;
		 int posicion = 0;

		printf("\n ## Lista de Elementos ##\n");
		while(listaAux != NULL){
			posicion++;
			printf("Posicion %d:", posicion);
	        
	        //mostrarDatosNodo(listaAux);
	        mostrarDatosNodo2(listaAux->dato);
	        
			listaAux = listaAux->siguiente;
		}	
	}
}

// j)	Contar la cantidad total de Elementos.
int totalElementos(tLista* pLista) {
	int cantidadElementos = 0;
	if(!listaVacia(pLista)){
		tLista* listaAux = pLista;
		
		while(listaAux != NULL){
			cantidadElementos++;
			listaAux = listaAux->siguiente;
		}
	}
	return cantidadElementos;
}

tInfo cargarDatos(){
	tInfo dato;
    
    // Ingresar datos
    printf("\n ## CREAR ELEMENTO ##\n");
    printf("\tCampo int: ");
    scanf("%d", &dato.campoInt);    
    printf("\tCadena: ");
    scanf(" %49[^\n]", &dato.campoString);    
    printf("\tFloat: ");
    scanf("%f", &dato.campoFloat);
    
    return dato;
}


void mostrarDatosNodo(tLista* pNodo) {
	printf("\n--------------------------------\n");
    printf("## DATOS DEL ELEMENTOS ##\n");
    printf("Campo nro       : %d\n", pNodo->dato.campoInt);
    printf("Cadena              : %s\n", pNodo->dato.campoString);
    printf("Campo Float              : $%.2f\n", pNodo->dato.campoFloat);
    printf("--------------------------------\n");
}


void mostrarDatosNodo2(tInfo pDato) {
	printf("\n--------------------------------\n");
    printf("## DATOS DEL ELEMENTOS ##\n");
    printf("Campo nro       : %d\n", pDato.campoInt);
    printf("Cadena              : %s\n", pDato.campoString);
    printf("Campo Float              : $%.2f\n", pDato.campoFloat);
    printf("--------------------------------\n");
}

// k)	Liberar completamente la memoria de la lista.
void liberarTodaLaMemoria(tLista** pLista) {
    tLista* listaAux = *pLista;
    tLista* siguiente;
    
    while (listaAux != NULL) {
        siguiente = listaAux->siguiente;
        free(listaAux);
        listaAux = siguiente;
    }
    
    *pLista = NULL;
    printf("Memoria de la lista liberada correctamente.\n");
}





