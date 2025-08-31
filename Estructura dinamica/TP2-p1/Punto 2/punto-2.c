/*
2. Modificar el ejercicio 1 para implementar todas las operaciones básicas de una lista enlazada: 
a) Inicializar la lista (establecer puntero en NULL). 
b) Verificar si una lista está vacía. 
c) Insertar el primer videojuego (nodo) de la lista. 
d) Insertar un videojuego al principio de la lista. 
e) Insertar un videojuego en una posición específica. 
f) Eliminar el primer videojuego de la lista. 
g) Eliminar un videojuego de una posición específica. 
h) Buscar un videojuego por ID y retornar su posición. 
i) Visualizar todos los videojuegos de la lista. 
j) Contar la cantidad total de videojuegos.
k) Liberar completamente la memoria de la lista.Crear un menú principal que permita probar todas estas funciones. 
*Plus: Insertar un videojuego al final de la lista. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCARD 50
typedef char tstring[MAXCARD];

/*Estructuras de la Lista*/
typedef struct 
{
    int idJuego;
    tstring titulo;
    int anoLanzamiento;
    float precio;

}tDatovideojuego;

/*Nodo de la Lista*/
typedef struct Nodo 
{
    tDatovideojuego videojuego;
    struct Nodo* siguiente;

}tListavideojuegos;

tListavideojuegos* crearNodo();

/*Prototipos*/

bool listaVacia(tListavideojuegos*);
void inicializarLista(tListavideojuegos**);
void mostrarDatosNodo(tListavideojuegos* );
void liberarMemoria(tListavideojuegos**);

/*NODO*/

tListavideojuegos* crearNodo()
{
    tListavideojuegos* Nodo = NULL;
    /*Asignar memoria para el primer Nodo*/
    Nodo = (tListavideojuegos*)malloc(sizeof(tListavideojuegos));

    if(Nodo == NULL)
    {
        printf("!ERROR! No se puede Asignar Memoria");
        return NULL;
    }
    /*Ingresar Datos*/

    printf("\n****************Lista de Videojuegos*****************\n");
    printf("\tid del Juego: ");
    scanf("%d",&Nodo->videojuego.idJuego);
    fflush(stdin);
    printf("\ttitulo del Juego: ");
    scanf("%[^\n]", Nodo->videojuego.titulo);
    fflush(stdin);
    printf("\tAno de Lanzamiento: ");
    scanf("%d", &Nodo->videojuego.anoLanzamiento);
    fflush(stdin);
    printf("\tPrecio del Juego: ");
    scanf("%f", &Nodo->videojuego.precio);
    fflush(stdin);
    return Nodo;
}

void mostrarDatosNodo(tListavideojuegos* Nodo)
{
    printf("***********************************************************\n");
    printf("\tid del Juego: %d\n", Nodo->videojuego.idJuego);
    printf("\ttitulo del Juego: %s\n", Nodo->videojuego.titulo);
    printf("\tAno de Lanzamiento: %d\n", Nodo->videojuego.anoLanzamiento);
    printf("\tPrecio del Juego: %2.f\n", Nodo->videojuego.precio);
    printf("***********************************************************\n");
}
/*Recordar que es necesario "**" para modificar el nodo original */

void liberarMemoria(tListavideojuegos** Nodo)
{
    /*Fuera Bicho*/
    free(*Nodo);
    *Nodo = NULL;
    printf("\nSoy el ASSassins creed de una negra que libera\n");
}

bool listaVacia(tDatovideojuego * pLista)
{
    return (pLista == NULL);
}

/*inicio*/
int main()
{
    tListavideojuegos* primerNodo = crearNodo();
    if(primerNodo != NULL)
    {
        mostrarDatosNodo(primerNodo);
        liberarMemoria(&primerNodo);
        
    }else
    {
        printf("\nNO HAY LUGAR PIBE");
        exit(1);
    }
    /*verificar si se libero la memoria*/
    if(primerNodo == NULL)
    {
        printf("Si hay lugar pibe ubicate\n");
    }
    return 0;
}
