#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 40

typedef char tstring[MAX];

int calcularCadena(tstring[],int);

int main()
{
    tstring cadenas[] = {"hola", "mundo", "openai", "c", "codigo"};
    int dimension = 5;

    int longitud = calcularCadena(cadenas, dimension);
    printf("Cantidad de cadenas con longitud par: %d\n", longitud);

    return 0;   
}

int calcularCadena(tstring pCadena[], int pDimension)
{
    if(pDimension > 0)
    {
        int log = 0;
        while(pCadena[pDimension][log] != '\0')
        {
            log++;
        }

        bool esPar = (log % 2 == 0);

        return esPar + calcularCadena(pCadena, pDimension - 1);
    }
    return 0;
}
