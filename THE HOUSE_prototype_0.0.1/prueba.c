#include <stdio.h>
#include "mundo.h"

static const char* NOMBRE_DIR[NUM_DIR] = {"norte", "sur", "este", "oeste"};

int main()
{
    Habitacion casa[NUM_HAB];
    inicializarHabitaciones(casa);
    int id;
    int dir;
    for (id = 0; id < NUM_HAB; id++)
    {
        for (dir = 0; dir < NUM_DIR; dir++)
        {
            Salida s = casa[id].salidas[dir];
            if (s.destino == SIN_SALIDA) continue;

            printf("%s -> %s: %s%s\n",
                   casa[id].nombre, NOMBRE_DIR[dir],
                   casa[s.destino].nombre,
                   s.bloqueada ? " (bloqueada)" : "");
        }
    }
    return 0;
}