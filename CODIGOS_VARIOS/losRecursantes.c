/*6. Escribir una función recursiva que reciba como parámetro un arreglo de números enteros y la
cantidad de elementos que contiene, y retorne el número más grande del arreglo.
★ Ejemplo: para el arreglo [1, -2, 7, 4, 3], la función debería retornar 7, ya que es
el número más grande del arreglo. 
*/

#include <stdio.h>
#include <string.h>

#define MAX 5


typedef int vNum[];

/*Funcion Recursiva por parametro*/
int numeroMayorRec(vNum pNum, int n)
{
    if(n == 1)
    {
        return pNum[0];
    }
    int mayorPrevio = numeroMayorRec(pNum, n-1);
    if(pNum[n-1]> mayorPrevio)
    {
        return pNum[n-1];
    }else
    {
        return mayorPrevio;
    }
}

int main()
{
    vNum numeros ={20,12,3,45,90};
    numeroMayorRec(numeros,5);
    return 0;
}



