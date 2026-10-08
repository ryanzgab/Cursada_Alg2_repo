#include <stdio.h>
#include "mundo.h"
#include "objetos.h"

#ifndef UBICACION_LAMPARA
#define UBICACION_LAMPARA CUARTO_SECUNDARIO
#endif

/* ============================================================
   DEFINICION DE LOS OBJETOS: aqui se editan
   ============================================================ */
bool inicializarObjetos(Objeto* pOBJ)
{
    bool ok = true;
    int i;

    for (i = 0; i < NUM_OBJ; i++)
    {
        pOBJ[i] = (Objeto){NULL, NULL, EN_NINGUNA_PARTE};
    }

    /* id, nombre, descripcion, ubicacion inicial */
    ok &= agregarObjeto(pOBJ, LAMPARA, "lampara", "una lampara de aceite", UBICACION_LAMPARA);

    /* Control: todos los objetos del enum tienen que estar definidos */
    for (i = 0; i < NUM_OBJ; i++)
    {
        if (pOBJ[i].nombre == NULL)
        {
            printf("Error: el objeto %d esta en el enum pero no se definio\n", i);
            ok = false;
        }
    }
    return ok;
}

bool agregarObjeto(Objeto* pOBJ, int id, tString nombre, tString descripcion, int ubicacion)
{
    bool ubicacionValida;

    if (id < 0 || id >= NUM_OBJ)
    {
        printf("Objeto invalido: el id %d esta fuera de rango (0 a %d)\n", id, NUM_OBJ - 1);
        return false;
    }
    if (pOBJ[id].nombre != NULL)
    {
        printf("El objeto %d ya fue definido (%s)\n", id, pOBJ[id].nombre);
        return false;
    }
    ubicacionValida = (ubicacion >= 0 && ubicacion < NUM_HAB)
                   || ubicacion == EN_INVENTARIO
                   || ubicacion == EN_NINGUNA_PARTE;
    if (!ubicacionValida)
    {
        printf("No se pudo agregar %s: la ubicacion %d no es valida\n", nombre, ubicacion);
        return false;
    }
    pOBJ[id] = (Objeto){nombre, descripcion, ubicacion};
    return true;
}

void mostrarObjetos(const Objeto* pOBJ, int idHab)
{
    int i;
    for (i = 0; i < NUM_OBJ; i++)
    {
        if (pOBJ[i].ubicacion == idHab)
        {
            printf("Aqui hay %s.\n", pOBJ[i].descripcion);
        }
    }
}
