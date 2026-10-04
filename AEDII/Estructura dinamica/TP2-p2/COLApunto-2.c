/*2. Se requiere gestionar la asignación de documentos que se envían a una impresora. Los documentos
se imprimen a medida que van llegando, y salen de la cola de impresión una vez impresos. Los datos
que se requieren para el procesamiento de la impresión de los documentos son: IP de la PC que
envía el documento, Nombre del documento, Tipo de documento (01. docx - 02.pdf - 03.jpg -
04.png - 05.xlsx), tamaño en bytes. Se solicita realizar las funciones necesarias para que la
impresora emita los siguientes informes:
a) La cantidad de documentos de formato de imágenes que se encuentran en cola de impresión.
b) El tamaño total de todos los documentos que se encuentran en cola de impresión (expresado
en megabytes).
c) El próximo documento a ser impreso. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef char tString[MAX];

tString extDoc[]={"docx","pdf","jpg","png","xlsx"};


typedef struct 
{
    int ipPC, tipoDoc;
    float bytesTam;
    tString nombreDoc;
}tDatoDocumento;

typedef struct nodo
{
    tDatoDocumento* documento;
    struct nodo *siguiente;
}tNodoDocumento;

typedef struct 
{
    tNodoDocumento* principio;
    tNodoDocumento* final; 
}tColaDocumento;

void inicializarCola();
bool colaVacia();


