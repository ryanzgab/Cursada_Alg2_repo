#ifndef OBJETOS_H
#define OBJETOS_H

#include "mundo.h"

/* Valores especiales de "ubicacion" (los ids de habitacion son 0 o mayores) */
#define EN_INVENTARIO    -2
#define EN_NINGUNA_PARTE -3

enum idObjeto {LAMPARA, NUM_OBJ};

typedef struct
{
    tString nombre;
    tString descripcion;
    int ubicacion;
} Objeto;

/* Definicion de los objetos: se edita en objetos.c. Devuelve false si hay errores. */
bool inicializarObjetos(Objeto*);
bool agregarObjeto(Objeto*, int id, tString nombre, tString descripcion, int ubicacion);

void mostrarObjetos(const Objeto*, int);

#endif
