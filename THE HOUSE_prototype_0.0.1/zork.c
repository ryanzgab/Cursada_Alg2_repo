#include <stdio.h>
#include <string.h>
#include "mundo.h"
#include "objetos.h"

void buclePrincipal(const Habitacion*, Objeto*);
void describirLugar(const Habitacion*, const Objeto*, int);
int leerDireccion(const char*);

Habitacion CASA[NUM_HAB];
Objeto OBJETOS[NUM_OBJ];

int main(void)
{
    inicializarHabitaciones(CASA);
    inicializarObjetos(OBJETOS);
    buclePrincipal(CASA, OBJETOS);
    return 0;
}

void describirLugar(const Habitacion* pCASA, const Objeto* pOBJ, int id)
{
    mostrarHabitacion(&pCASA[id]);
    mostrarObjetos(pOBJ, id);
}

int leerDireccion(const char* texto)
{
    if (strcmp(texto, "norte") == 0 || strcmp(texto, "n") == 0) return NORTE;
    if (strcmp(texto, "sur")   == 0 || strcmp(texto, "s") == 0) return SUR;
    if (strcmp(texto, "este")  == 0 || strcmp(texto, "e") == 0) return ESTE;
    if (strcmp(texto, "oeste") == 0 || strcmp(texto, "o") == 0) return OESTE;
    return -1;
}

void buclePrincipal(const Habitacion* pCASA, Objeto* pOBJ)
{
    int actual = CUARTO_PRINCIPAL;
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