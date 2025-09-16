/*
1. Un sistema operativo requiere un programa que gestione la asignación de memoria para los procesos en 
espera de ejecución. Para ello, se almacena en una cola la siguiente información: identificador del proceso, 
tamaño de memoria solicitado, y tipo de proceso (1-sistema, 2-usuario). Se solicita: 
     (0,50 puntos) Codificar en lenguaje C las estructuras de datos necesarias para la declaración del tipo 
    tProcesoEnEspera adecuado. 
     (2 puntos) Implementar una función que permita asignar memoria (saldrá de la cola de espera para 
    ejecutarse) al próximo proceso en la cola de pendientes. La función debe obtener el primer proceso 
    que está en espera, mostrar sus datos en pantalla, simular la asignación de memoria (memoria para 
    su ejecución, no confundir con la memoria del nodo) y eliminarlo de la cola de procesos pendientes. 
     (2,50 puntos) Implementar una función que permita visualizar el detalle de los procesos que están en 
    la cola de pendientes.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100


/*Estructuras*/
typedef char tString[MAX];
tString tipProc[]={"Sistema","Usuario"};
typedef struct 
{
    int idProceso, tamMemoria, tipoProceso;
}tProceso;

typedef struct nodo
{
    tProceso proceso;
    struct nodo* siguiente;
}tNodoProceso;

typedef struct 
{
    tNodoProceso* primero;
    tNodoProceso* final;
}tColaProceso;

/*Prototipado*/
void incializarCola(tColaProceso*);
bool colaVacia(tColaProceso);

void insertarProceso(tColaProceso*, tProceso);
void asignarMemoria(tColaProceso*);
void visualizarProceso(tProceso);
void visualizarCola(tColaProceso);


void incializarCola(tColaProceso* pColaProceso)
{
    pColaProceso->primero= NULL;
    pColaProceso->final=NULL;

};

bool colaVacia(tColaProceso pColaProceso)
{
    return(pColaProceso.primero==NULL && pColaProceso.final==NULL);
}

void insertarProceso(tColaProceso* pColaproceso, tProceso pProceso)
{
    tNodoProceso* nuevoProceso;
    nuevoProceso=(tNodoProceso*)malloc(sizeof(tNodoProceso));
    nuevoProceso->proceso=pProceso;
    nuevoProceso->siguiente=NULL;
    if(colaVacia(*pColaproceso))
    {
        pColaproceso->primero=nuevoProceso;
        pColaproceso->final=nuevoProceso;
    }else
    {
        pColaproceso->final->siguiente=nuevoProceso;
        pColaproceso->final=nuevoProceso;
    }
}

void asignarMemoria(tColaProceso* pColaProceso)
{
    if(pColaProceso->primero == NULL)
    {
        printf("No hay procesos");
        return;
    }
    tNodoProceso* pAux= pColaProceso->primero;
    /*Mostrar Datos del Primero Dato*/

    /*Sacar de la cola el Primer Dato*/
    pColaProceso->primero= pAux->siguiente;
    if(pColaProceso->primero == NULL)
    {
        pColaProceso->final=NULL;
    }
    free(pAux);
}

void visualizarProceso(tProceso pProceso)
{
    printf("id Proceso[%02d]-----Tamaño de Memoria[%04d]-------TipoProceso[%s]", pProceso.idProceso, pProceso.tamMemoria, tipProc[pProceso.tipoProceso]);
}

void visualizarCola(tColaProceso pColaProceso)
{
    tNodoProceso* pAux=pColaProceso.primero;
    int cantProcesos=0;
    while(pAux == NULL)
    {
        cantProcesos++;
        visualizarProceso(pAux->proceso);
        pAux= pAux->siguiente;
    }
    printf("Cantidad de procesos: %d", cantProcesos);
}