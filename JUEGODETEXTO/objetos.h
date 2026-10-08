#ifndef PROPOBJETOS_H
#define PROPOBJETOS_H

#define MAX_CAR 100

/* Valores especiales de "ubicacion" (los ids de habitacion son 0 o mayores) */
#define EN_INVENTARIO    -2
#define EN_NINGUNA_PARTE -3

enum idObjeto {LAMPARA, NUM_OBJ};

typedef char tString[MAX_CAR]; 

typedef struct
{
    tString nombre;
    tString descripcion;
    int ubicacion;
} Objeto;

void inicializarObjetos(Objeto*);
void mostrarObjetos(const Objeto*, int);

#endif