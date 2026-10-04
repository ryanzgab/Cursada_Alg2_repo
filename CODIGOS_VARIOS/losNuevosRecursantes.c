/*7. Se cuenta con un arreglo de artículos correspondientes a los ítems que se deben comprar para
reponer el stock de un negocio.
Se solicita codificar una función recursiva que, a partir del arreglo de artículos y su dimensión
recibidos como parámetros, devuelva la cantidad total de artículos que se deben adquirir.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define MAX 5

typedef struct
{
    int codigo,cantidad;
    float precio;
}tArticulo;

tArticulo articulos[MAX];

void articulosMercado(tArticulo pArticulo[], int n)
{
    int i, totalArticulos;
    tArticulo* pAux = pArticulo;

    for (i = 1; i < MAX; i++)
    {
        printf("==INGRESE CODIGO DEL ARTICULO==\n");
        fflush(stdin);
        scanf("%d",&pAux[i].codigo);
        printf("==CANTIDAD DE ARTICULOS==\n");
        fflush(stdin);
        scanf("%d", &pAux[i].cantidad);
        printf("==PRECIO DEL ARTICULO==\n");
        fflush(stdin);
        scanf("%f",&pAux[i].precio);
        printf("======== ARTICULO CARGADO=====\n");
        totalArticulos =+pAux[i].cantidad;
    }
    printf("=====ARTICULOS=====\n");
    for(i=1; i<MAX; i++)
    {
        printf("[#]-(N:%d) Cant: %d -- Prec: %.2f\n\n", pAux[i].codigo,pAux[i].cantidad,pAux[i].precio);
    }
    printf("=====TOTAL DE ARTICULOS %d ====\n",totalArticulos);

    if(pAux[0].cantidad != 0 || pAux[MAX-1].cantidad != 0)
    
    {
        articulosMercado(pArticulo, n);
    }
}

int main()

{
    articulosMercado(articulos,MAX);
    return 0;
}