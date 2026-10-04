#ifndef OBJETOS_H
#define OBJETOS_H

/* Valores especiales de "ubicacion" (los ids de habitacion son 0 o mayores) */
#define EN_INVENTARIO    -2
#define EN_NINGUNA_PARTE -3

enum idObjeto {LAMPARA, NUM_OBJ};

typedef struct
{
    const char* nombre;
    const char* descripcion;
    int ubicacion;
} Objeto;

void inicializarObjetos(Objeto*);
void mostrarObjetos(const Objeto*, int);

#endif