#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mundo.h"
#include "objetos.h"

void buclePrincipal(tMapa*, Objeto*);
void describirLugar(tMapa*, const Objeto*, int);
bool hayLuz(const tMapa*, const Objeto*, int);
int leerDireccion(tString);

tMapa MAPA;
Objeto OBJETOS[NUM_OBJ];

int main(void)
{
    bool ok = inicializarHabitaciones(&MAPA);
    ok = inicializarObjetos(OBJETOS) && ok;

    if (!ok)
    {
        printf("Hay errores en la definicion del mundo. Revisa mundo.c y objetos.c\n");
        return 1;
    }

#ifdef DEPURAR
    visualizarMatriz(&MAPA);
#endif

    buclePrincipal(&MAPA, OBJETOS);
    return 0;
}

bool hayLuz(const tMapa* pMapa, const Objeto* pOBJ, int id)
{
    if (pMapa->habitaciones[id].luz)
    {
        return true;
    }
    /* regla provisoria: la lampara ilumina si la llevas o esta en la habitacion */
    return pOBJ[LAMPARA].ubicacion == EN_INVENTARIO
        || pOBJ[LAMPARA].ubicacion == id;
}

void describirLugar(tMapa* pMapa, const Objeto* pOBJ, int id)
{
    Habitacion* pHab = &pMapa->habitaciones[id];

    if (!hayLuz(pMapa, pOBJ, id))
    {
        printf("\nEsta muy oscuro. No ves nada.\n");
        return;
    }

    if (pHab->visitada)
    {
        mostrarNombre(pHab);
    }
    else
    {
        mostrarHabitacion(pHab);
    }

    mostrarObjetos(pOBJ, id);
    pHab->visitada = true;
}

int leerDireccion(tString texto)
{
    if (strcmp(texto, "norte") == 0 || strcmp(texto, "n") == 0) return NORTE;
    if (strcmp(texto, "sur")   == 0 || strcmp(texto, "s") == 0) return SUR;
    if (strcmp(texto, "este")  == 0 || strcmp(texto, "e") == 0) return ESTE;
    if (strcmp(texto, "oeste") == 0 || strcmp(texto, "o") == 0) return OESTE;
    return -1;
}

void buclePrincipal(tMapa* pMapa, Objeto* pOBJ)
{
    int actual = CUARTO_PRINCIPAL;
    char linea[MAX_CAR];

    describirLugar(pMapa, pOBJ, actual);

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

        int destino = destinoEn(pMapa, actual, dir);
        if (destino == SIN_SALIDA)
        {
            printf("No puedes ir por ahi.\n");
        }
        else if (salidaBloqueada(pMapa, actual, destino))
        {
            printf("La salida esta bloqueada.\n");
        }
        else
        {
            actual = destino;
            describirLugar(pMapa, pOBJ, actual);
        }
    }
}
