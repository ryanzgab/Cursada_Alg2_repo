#include "habitaciones.h"
#include "objetos.h"

void describirLugar(Habitacion*, const Objeto*, int);
bool hayLuz(const Habitacion*, const Objeto*, int);

void inicializarHabitaciones(Habitacion* pCASA)
{
    pCASA[CUARTO_INVITADOS] = (Habitacion){
        .nombre = "Cuarto de invitados",
        .descripcion = "Estas en un cuarto maloliente",
        .salidas = {SALIDA(CUARTO_PASILLO), NO_SALIDA, NO_SALIDA, NO_SALIDA},
        .luz = true
    };
    pCASA[CUARTO_PASILLO] = (Habitacion){
        .nombre = "Pasillo",
        .descripcion = "Un largo pasillo se ve unas dos puertas abarrotadas",
        .salidas = {SALIDA(CUARTO_BANO), SALIDA(CUARTO_INVITADOS), BLOQUEADA(CUARTO_ABARROTADO), SALIDA(CUARTO_COCINA)},
        .luz = true
    };
    pCASA[CUARTO_COCINA] = (Habitacion){
        .nombre = "Cocina",
        .descripcion = "Una Cocina con un horrible olor a sobaco",
        .salidas = {NO_SALIDA, SALIDA(CUARTO_LIVING), SALIDA(CUARTO_PASILLO), NO_SALIDA},
        .luz = true
    };
    pCASA[CUARTO_LIVING] = (Habitacion){
        .nombre = "Living",
        .descripcion = "Un living con un sillo lleno de forros usados",
        .salidas = {SALIDA(CUARTO_LIVING), NO_SALIDA, NO_SALIDA, NO_SALIDA},
        .luz = false
    };
    pCASA[CUARTO_BANO] = (Habitacion){
        .nombre = "Ba\xA4o",
        .descripcion = "Si creiste que podia oler peor, preparate para el olor a culo que se siente aca",
        .salidas = {NO_SALIDA, SALIDA(CUARTO_PASILLO), NO_SALIDA, NO_SALIDA},
        .luz = true
    };

}
void mostrarNombre(const Habitacion* pHab)
{
    printf("\n%s\n", pHab->nombre);
}

void mostrarHabitacion(const Habitacion* pHab)
{
    printf("\n%s\n%s\n", pHab->nombre, pHab->descripcion);
}

void inicializarObjetos(Objeto* pOBJ)
{
    pOBJ[LAMPARA] = (Objeto){
        "lampara",
        "una lampara de aceite",
        CUARTO_COCINA
    };
}

void mostrarObjetos(const Objeto* pOBJ, int idHab)
{
    int i;
    for (i = 0; i < NUM_OBJ; i++)
    {
        if (pOBJ[i].ubicacion == idHab)
        {
            printf("Se logra ver.. %s.\n", pOBJ[i].descripcion);
        }
    }
}

void describirLugar(Habitacion* pCASA, const Objeto* pOBJ, int id)
{
    Habitacion* pHab = &pCASA[id];

    if (!hayLuz(pCASA, pOBJ, id))
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

bool hayLuz(const Habitacion* pCASA, const Objeto* pOBJ, int id)
{
    if (pCASA[id].luz)
    {
        return true;
    }
    return pOBJ[LAMPARA].ubicacion == EN_INVENTARIO
        || pOBJ[LAMPARA].ubicacion == id;
}
