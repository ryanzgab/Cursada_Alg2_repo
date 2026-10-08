#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mapa.h"
#include "comandos.h"

/*El uso de constantes como parametros es para establecer solo lectura*/
void inicializarMapa(Habitacion*, Objeto*);
void buclePrincipal(Habitacion*, Objeto*);


Habitacion CASA[NUM_HAB];
Objeto OBJETOS[NUM_OBJ];

int main()
{
    inicializarMapa(CASA, OBJETOS);
    buclePrincipal(CASA, OBJETOS);
    return 0;
}

void inicializarMapa(Habitacion* pCASA, Objeto* pOBJ)
{
    inicializarHabitaciones(pCASA);
    inicializarObjetos(pOBJ);
}


void buclePrincipal(Habitacion* pCASA, Objeto* pOBJ)
{
    int actual = CUARTO_INVITADOS;
    char linea[MAX_CAR];
 
    describirLugar(pCASA, pOBJ, actual);
 
    while (1)
    {
        printf("\n> ");
        if (fgets(linea, sizeof linea, stdin) == NULL) break;
        linea[strcspn(linea, "\n")] = '\0';
 
        if (strcmp(linea, "salir") == 0) break;
 
        int dir = leerDireccion(linea);
        if (dir < 0)
        {
            printf("No entiendo eso.\n");
            continue;
        }
 
        Salida s = pCASA[actual].salidas[dir];
        if (s.destino == SIN_SALIDA)
        {
            printf("No puedes ir por ahi.\n");
        }
        else if (s.bloqueada)
        {
            printf("La salida esta bloqueada.\n");
        }
        else
        {
            actual = s.destino;
            describirLugar(pCASA, pOBJ, actual);
        }
    }
}