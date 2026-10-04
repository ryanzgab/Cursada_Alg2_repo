#ifndef MUNDO_H
#define MUNDO_H

#define MAX_CAR    100
#define SIN_SALIDA -1

#define NO_SALIDA      {SIN_SALIDA, 0}
#define SALIDA(d)      {(d), 0}
#define BLOQUEADA(d)   {(d), 1}

enum Direcciones {NORTE, SUR, ESTE, OESTE, NUM_DIR};
enum idHabitacion {CUARTO_PRINCIPAL, CUARTO_SECUNDARIO, CUARTO_TERCIARIO, NUM_HAB};

typedef struct
{
    int destino;      /* id de la habitacion destino, o SIN_SALIDA */
    int bloqueada;    /* 0 = abierta, 1 = bloqueada */
} Salida;

typedef struct
{
    const char* nombre;
    const char* descripcion;
    Salida salidas[NUM_DIR];
} Habitacion;

void inicializarHabitaciones(Habitacion*);
void mostrarHabitacion(const Habitacion*);

#endif