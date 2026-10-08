#include "propobjetos.h"
#include "propmapa.h"

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
            printf("Aqui hay %s.\n", pOBJ[i].descripcion);
        }
    }
}
