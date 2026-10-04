/*5. Escribir en lenguaje C, la declaración del tipo de dato tGrafoNoPonderado, para un grafo no 
ponderado de hasta 7 vértices. Utilizar la implementación de grafos con arrays. Además, escribir 
las funciones para: 
a) iniciar el grafo 
b) agregar un vértice al grafo  
c) agregar un arco al grafo 
d) visualizar la matriz de adyacencia de un grafo*/

#include <stdio.h>
#include <stdbool.h>

#define N 7

typedef int tVertice;

typedef struct 
{
    tVertice origen;
    tVertice destino;
}tArista;

typedef bool tConjuntoVertices[N];
typedef bool tConjuntoAristas[N][N];

typedef struct 
{
    tConjuntoVertices vertice;
    tConjuntoAristas arista;
}tGrafoNoPonderado;

void inicializarGrafo(tGrafoNoPonderado*);
void agregarVertice(tGrafoNoPonderado*,tVertice);
void agregarArista(tGrafoNoPonderado*,tArista);
void visualizarGrafo(tGrafoNoPonderado);


int maximoVertice(tGrafoNoPonderado);
bool existeVertice(tGrafoNoPonderado, tVertice);
bool existeArista(tGrafoNoPonderado, tArista);

int main()
{
    tGrafoNoPonderado grafoNoPonderado;

}

void inicializarGrafo(tGrafoNoPonderado* pGrafo)
{
    int i,j;

    for(i=0; i<N; i++)
    {
        pGrafo->vertice[i] = false;
        for(j=0; j<N; j++)
        {
            pGrafo->arista[i][j] = false;
        }
    }
    printf("Grafo Inicializado");
}

void agregarVertice(tGrafoNoPonderado* pGrafo, tVertice pVertice)
{
    pGrafo->vertice[pVertice] = true;

    printf("Vertice %d Agregado ", pVertice);
}

void agregarArista(tGrafoNoPonderado* pGrafo, tArista pArista)
{
    bool aristaValida = existeVertice(*pGrafo, pArista.origen) && existeVertice(*pGrafo, pArista.destino);
    if(aristaValida)
    {
        pGrafo->arista[pArista.origen][pArista.destino] = true;
        printf("Arista Activada %d,%d", pArista.origen, pArista.destino);
    }else
    {
        printf("Arista no Valida");
    }
}

int maximoVertice(tGrafoNoPonderado pGrafo)
{
    int i;
    int MAX = 0;

    for(i=1;i<=N;i++)
    {
        if(pGrafo.vertice[i] == true)
        {
            MAX = i;
        }
    }
    return MAX;
}

void visualizarGrafo(tGrafoNoPonderado pGrafo)
{
    int i,j;
    int MaxVertice = maximoVertice(pGrafo);

    for(i=1;i<=MaxVertice;i++)
    {
        for(j=1;j<=MaxVertice;j++)
        {
            tArista aristaActual = {.origen = i, .destino = j};
            if(existeArista(pGrafo, aristaActual))
            {
                printf("1\t");
            }else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

bool existeVertice(tGrafoNoPonderado pGrafo, tVertice pVertice)
{
    return pGrafo.vertice[pVertice] == true;
}

bool existeArista(tGrafoNoPonderado pGrafo, tArista pArista)
{
    return (pGrafo.arista[pArista.origen][pArista.destino] == true) && existeVertice(pGrafo, pArista.origen ) && existeVertice(pGrafo, pArista.destino);
}