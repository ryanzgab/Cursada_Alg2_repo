#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>


typedef struct nodo {
    int id; 
	int lanzamiento;
    float precio;
    char titulo[50];
    struct nodo *siguiente;
} tListaVideojuegos;

tListaVideojuegos *lista;

void inicializarLista();
bool listaVacia(tListaVideojuegos*);
void insertarPrimero(int, int, float, char[]);
void insertarAdelante(int, int, float, char []);
void insertarElemento(int, int, float, char[]);
void visualizarElemento(tListaVideojuegos*);
void liberarLista();


int main(){
	inicializarLista();
	printf("Lista vacia? %s\n", listaVacia(lista) ? "si" : "no");
	insertarElemento(3, 2002, 45.5, "HALO");
	printf("Lista vacia? %s\n", listaVacia(lista) ? "si" : "no");
	insertarElemento(5, 2006, 50, "gta" );
	insertarElemento(7, 2020, 1000, "the forest");
	visualizarElemento(lista);
	liberarLista();
	
	return 0;
}

void inicializarLista(){
	
	lista = NULL;
	
}

bool listaVacia(tListaVideojuegos* pLista){
	
	if(pLista == NULL){
		return true;
	}else{
		return false;
	}
}

void insertarElemento(int pId, int pLanza, float pPrecio, char pTitulo[]){
	
	if(listaVacia(lista)){
		insertarPrimero(pId, pLanza, pPrecio, pTitulo);
	}else{
		insertarAdelante(pId, pLanza, pPrecio, pTitulo);
	}
}

void insertarPrimero(int pId, int pLanza, float pPrecio, char pTitulo[]){
	
	tListaVideojuegos* nuevoNodo;
	
	nuevoNodo = (tListaVideojuegos*) malloc(sizeof(tListaVideojuegos));
	
	nuevoNodo->id = pId;
	nuevoNodo->lanzamiento = pLanza;
	nuevoNodo->precio = pPrecio;
	strcpy(nuevoNodo->titulo, pTitulo);
	
	nuevoNodo->siguiente = NULL;
	
	lista = nuevoNodo;
	
	printf("Primer elemento insertado! \n");
}

void insertarAdelante(int pId, int pLanza, float pPrecio, char pTitulo[]){
	
	tListaVideojuegos* nuevoNodo;
	
	nuevoNodo = (tListaVideojuegos*) malloc(sizeof(tListaVideojuegos));
	
	nuevoNodo->id = pId;
	nuevoNodo->lanzamiento = pLanza;
	nuevoNodo->precio = pPrecio;
	strcpy(nuevoNodo->titulo, pTitulo);
	
	nuevoNodo->siguiente = lista;
	
	lista = nuevoNodo;
	
	printf("Elemento insertado! \n");
	
	
}


void visualizarElemento(tListaVideojuegos* pLista){
	
	tListaVideojuegos* aux;
	aux = pLista;
	
	if(!listaVacia(pLista)){
		printf("\n======Detalles de los elementos de la lista ======\n");
		while(aux != NULL){
			printf("\t%d\n", aux->id);
			printf("\t%d\n", aux->lanzamiento);
			printf("\t%.2f\n", aux->precio);
			printf("\t%s\n", aux->titulo);
			aux = aux -> siguiente;
		}
	}else{
		printf("\nLa lista está vacia\n");
	}
}



void liberarLista(){
	tListaVideojuegos *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
        aux = NULL;
   
}
}
