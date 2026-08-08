#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

/*Datos Personalizados*/
typedef char tString[MAX];
typedef tString tArrayString[6];

typedef struct 
{
    int edad, tipoConsulta;
    tString nombre;
}tPaciente;

typedef struct nodo
{
    tPaciente paciente;
    struct nodo* siguiente;
}tListaPaciente;

tArrayString tposConsultas = {" ", "Urgencias","General","Pediatria"};

/*Prototipado*/
void inicializarLista(tListaPaciente**);
bool listaVacia(tListaPaciente*);

void insertaElemento(tListaPaciente**, tPaciente);
void insertarPrimerElemento(tListaPaciente**, tPaciente);
void insertarElementoAlPrincipio(tListaPaciente**, tPaciente);

void buscarPaciente(tListaPaciente*,int);
void eliminarenPos(tListaPaciente**,int);

void mostrarCantPacientes(tListaPaciente*);

/*Funciones*/

void inicializarLista(tListaPaciente** pLista)
{
    *pLista = NULL;
    printf("Lista Iniciada");
}

bool listaVacia(tListaPaciente* pLista)
{
    return (pLista == NULL);
}

void buscarPaciente(tListaPaciente* pLista, int pInt)
{
    tListaPaciente* pAux = pLista;
    int pos = 0;
    int idEncontrado = -1;

    while(pAux != NULL && pos != -1)
    {
        pos ++;
        if(pAux->paciente.tipoConsulta == pInt)
        {
            idEncontrado = pos;
        }
        pAux = pAux->siguiente;
    }
}

void eliminarenPos(tListaPaciente** pLista, int pos)
{
    if(*pLista == NULL)
    {
        printf("Lista vacia");
        return;
    }
    if(pos < 0)
    {
        printf("ERROR");
        return;
    }

    tListaPaciente *pAux = pLista;
    
    int i;

    for(i=1;i<pos-1;i++)
    {
        pAux = pAux->siguiente;
    }

    tListaPaciente* elementoElim = pAux->siguiente;

    pAux->siguiente = elementoElim->siguiente;

    free(elementoElim);
    elementoElim = NULL;

}

void mostrarCantPacientes(tListaPaciente* pLista)
{
    	if(listaVacia(pLista)){
		printf("No hay Elementos para mostrar en la lista!\n");
		return;
	}else
    {
		tListaPaciente* pAux = pLista;
		int posicion = 0;
        int i;

		printf("\n ## Lista de Elementos ##\n");
		
		while(pAux != NULL)
        {
		    i=pAux->paciente.tipoConsulta;
			
			cantSegTipoContenido[i] = cantSegTipoContenido[i] + 1;
			
			pAux = pAux->siguiente;
		}	
	
	}
}