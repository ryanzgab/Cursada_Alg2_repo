#include <stdio.h>
#include <stdbool.h>
#include "propmapa.h"


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