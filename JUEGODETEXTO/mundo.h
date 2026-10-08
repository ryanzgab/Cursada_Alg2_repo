#ifndef MUNDO_H
#define MUNDO_H

#include <stdbool.h>

#define MAX_CAR 100
#define SIN_SALIDA -1

#define NO_SALIDA      {SIN_SALIDA, false}
#define SALIDA(d)      {(d), false}
#define BLOQUEADA(d)   {(d), true}

typedef char tString[MAX_CAR];  /*Cadena de caracteres*/

enum Direcciones {NORTE, SUR, ESTE, OESTE, NUM_DIR}; /*0-NORTE, 1-SUR, 2-ESTE, 3-OESTE*/
enum idHabitacion /*Identificadores de  Habitaciones*/
{
    CUARTO_INVITADOS, 
    CUARTO_PASILLO, 
    CUARTO_ABARROTADO, 
    CUARTO_COCINA, 
    CUARTO_LIVING,
    CUARTO_BANO, 
    NUM_HAB /*Numero Maximo de habitaciones*/
}; 

typedef struct
{
    int destino;      /* id de la habitacion destino, o SIN_SALIDA */
    bool bloqueada;    /* 0 = abierta, 1 = bloqueada */
} Salida;

typedef struct
{
    tString nombre;
    tString descripcion;
    bool visitada;    /* ya la viste alguna vez */
    bool luz;         /* tiene luz propia */
    Salida salidas[NUM_DIR];
} Habitacion;

void inicializarHabitaciones(Habitacion*);
void mostrarNombre(const Habitacion*);
void mostrarHabitacion(const Habitacion*);

#endif