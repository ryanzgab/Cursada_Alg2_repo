#include <stdio.h>
#include "mundo.h"

void inicializarHabitaciones(Habitacion* pCASA)
{
    pCASA[CUARTO_PRINCIPAL] = (Habitacion){
        "Cuarto de invitados",
        "Estas en un cuarto con montones de forros tirados",
        {SALIDA(CUARTO_SECUNDARIO), NO_SALIDA, NO_SALIDA, NO_SALIDA}
    };
    pCASA[CUARTO_SECUNDARIO] = (Habitacion){
        "Pasillo",
        "Un largo pasillo se ve unas dos puertas abarrotadas",
        {NO_SALIDA, SALIDA(CUARTO_PRINCIPAL), SALIDA(CUARTO_TERCIARIO), NO_SALIDA}
    };
    pCASA[CUARTO_TERCIARIO] = (Habitacion){
        "Cocina",
        "Una Cocina con un horrible olor a sobaco",
        {NO_SALIDA, NO_SALIDA, NO_SALIDA, SALIDA(CUARTO_SECUNDARIO)}
    };
}

void mostrarHabitacion(const Habitacion* pHab)
{
    printf("\n%s\n%s\n", pHab->nombre, pHab->descripcion);
}

