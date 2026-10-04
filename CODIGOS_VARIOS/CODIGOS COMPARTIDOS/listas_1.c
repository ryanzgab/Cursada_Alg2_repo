#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int tElem;

typedef struct nodo {
    tElem elem;
    struct nodo *siguiente;
} tLista;

tLista *lista;

void inicializarLista();
bool listaVacia(tLista*);
void insertarPrimero(tElem);
void insertarAdelante(tElem );
void insertarElemento(tElem);
void eliminarPrimero();
void visualizarElemento(tLista*);
void insertarK(int, tElem);
void eliminarK(int);
void liberarLista();


int main(){
	inicializarLista();
	printf("Lista vacia? %s\n", listaVacia(lista) ? "si" : "no");
	insertarElemento(5);
	printf("Lista vacia? %s\n", listaVacia(lista) ? "si" : "no");
	insertarElemento(8);
	insertarElemento(3);
	visualizarElemento(lista);
	eliminarPrimero();
	visualizarElemento(lista);
	insertarK(2, 7);
	visualizarElemento(lista);
	eliminarK(2);
	visualizarElemento(lista);
	liberarLista();
	
	return 0;
}

void inicializarLista(){
	
	lista = NULL;
	
}

bool listaVacia(tLista* pLista){
	
	if(pLista == NULL){
		return true;
	}else{
		return false;
	}
}

void insertarElemento(tElem pElem){
	
	if(listaVacia(lista)){
		insertarPrimero(pElem);
	}else{
		insertarAdelante(pElem);
	}
}

void insertarPrimero(tElem pElem){
	
	tLista* nuevoNodo;
	
	nuevoNodo = (tLista*) malloc(sizeof(tLista));
	
	nuevoNodo->elem = pElem;
	
	nuevoNodo->siguiente = NULL;
	
	lista = nuevoNodo;
	
	printf("Primer elemento insertado! \n");
}

void insertarAdelante(tElem pElem){
	
	tLista* nuevoNodo;
	
	nuevoNodo = (tLista*) malloc(sizeof(tLista));
	
	nuevoNodo->elem = pElem;
	
	nuevoNodo->siguiente = lista;
	
	lista = nuevoNodo;
	
	printf("Elemento insertado! \n");
	
	
}

void eliminarPrimero(){
	
	tLista* nodoSuprimir;
	
	if(listaVacia(lista)){
		
		printf("La lista no contiene elementos para eliminar\n");

	}else{
		
		nodoSuprimir = lista;
	}
	
	lista = lista->siguiente;
	
	free(nodoSuprimir);
	
	nodoSuprimir = NULL;
	
	printf("Primer elemento eliminado! \n");
}

void visualizarElemento(tLista* pLista){
	
	tLista* aux;
	aux = pLista;
	
	if(!listaVacia(pLista)){
		printf("\n======Detalles de los elementos de la lista ======\n");
		while(aux != NULL){
			printf("\t%d\n", aux->elem);
			aux = aux -> siguiente;
		}
	}else{
		printf("\nLa lista está vacia\n");
	}
}

void insertarK(int k, tElem pDato){
	
	tLista* nuevoNodo, *aux;
    int i;
    aux = lista;

    for (i = 0; i < k - 1; i++) {
        aux = aux->siguiente;
    }

    nuevoNodo = (tLista*) malloc(sizeof(tLista));

    nuevoNodo->elem = pDato;

    nuevoNodo->siguiente = aux->siguiente;

  
    aux->siguiente = nuevoNodo;

    printf("Elemento insertado en la posicion %d!\n", k);
}

void eliminarK(int k){
	
	tLista* nodoSuprimir, *aux;
    int i;
    aux = lista;

  	for (i = 0; i < k - 1; i++) {
 	    aux = aux->siguiente;
    }
    
    nodoSuprimir = aux->siguiente;

    aux->siguiente = nodoSuprimir->siguiente;

    
    free(nodoSuprimir);


    nodoSuprimir = NULL;

    printf("Elemento de la posicion %d eliminado\n", k);
}

void liberarLista(){
	tLista *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
        aux = NULL;
   
}
}
