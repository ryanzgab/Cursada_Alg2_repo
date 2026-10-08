#ifndef MUNDO_H
#define MUNDO_H

#include <stdbool.h>

typedef const char* tString;   /* texto de solo lectura */

#define MAX_CAR    100
#define SIN_ARCO   -1          /* celda vacia de la matriz */
#define SIN_SALIDA -1          /* resultado de destinoEn cuando no hay salida */

enum Direcciones {NORTE, SUR, ESTE, OESTE, NUM_DIR};
enum idHabitacion {CUARTO_PRINCIPAL, CUARTO_SECUNDARIO, CUARTO_TERCIARIO, SALA, SOTANO, PATIO, NUM_HAB};

typedef int tVertice;

typedef struct
{
    tVertice origen;
    int direccion;       /* NORTE, SUR, ESTE u OESTE */
    tVertice destino;
    bool bloqueada;
} tArco;

typedef struct
{
    tString nombre;
    tString descripcion;
    bool visitada;       /* ya la viste alguna vez */
    bool luz;            /* tiene luz propia */
} Habitacion;

typedef bool conjuntoVertices[NUM_HAB];
typedef int  conjuntoArcos[NUM_HAB][NUM_HAB];       /* direccion de i a j, o SIN_ARCO */
typedef bool conjuntoBloqueos[NUM_HAB][NUM_HAB];

typedef struct
{
    conjuntoVertices vertices;                      /* que habitaciones estan definidas */
    Habitacion habitaciones[NUM_HAB];
    conjuntoArcos arcos;
    conjuntoBloqueos bloqueos;
} tMapa;

/* Definicion del mundo: se edita en mundo.c. Devuelve false si hay errores. */
bool inicializarHabitaciones(tMapa*);

/* Operaciones del grafo */
void inicializarMapa(tMapa*);
bool existeHabitacion(const tMapa*, tVertice);
bool agregarHabitacion(tMapa*, tVertice, tString nombre, tString descripcion, bool luz);
bool agregarArco(tMapa*, tArco);        /* un solo sentido */
bool conectarDoble(tMapa*, tArco);      /* ida y vuelta, con la direccion opuesta */

/* Consultas */
int  destinoEn(const tMapa*, tVertice origen, int direccion);
bool salidaBloqueada(const tMapa*, tVertice origen, tVertice destino);
int  calcularGradoSalida(const tMapa*, tVertice);
int  calcularGradoEntrada(const tMapa*, tVertice);

/* Presentacion */
void mostrarHabitacion(const Habitacion*);
void mostrarNombre(const Habitacion*);
void visualizarMatriz(const tMapa*);

#endif
