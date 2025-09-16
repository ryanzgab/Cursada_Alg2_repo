/*6. Escribir una función recursiva que reciba como parámetro un arreglo de números enteros y la
cantidad de elementos que contiene, y retorne el número más grande del arreglo.
★ Ejemplo: para el arreglo [1, -2, 7, 4, 3], la función debería retornar 7, ya que es
el número más grande del arreglo. 
*/

#include <stdio.h>
#include <string.h>

#define MAX 5


int vNum[];

/*Funcion Recursiva por parametro*/
void numeroMayor(int pNum[], int n)
{
    int numMayor = pNum[0];
    int i;
    for(i=1;i<MAX;i++)
    {
        printf("ingrese un numero: ");
        fflush(stdin);
        scanf("%d",&pNum[i]);
    }

    for (i = 1; i < n; i++)
    {
        if(vNum[i]>numMayor) /*CASO BASE*/
        {
            numMayor=pNum[i];
        }
    }
    printf("num Mayor: %d\n",numMayor);

    if(pNum[i] == pNum[MAX])    /*CASO RECURSIVO*/
    {
        numeroMayor(pNum,n);
    }
}

int main()
{
    numeroMayor(vNum,MAX);
    return 0;
}

