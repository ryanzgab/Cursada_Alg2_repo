/*
 ███  █████ ████  ███ ███            ████  █   █ █   █ █████ █████ ████   ███   ████ 
█   █ █     █   █  █   █             █   █ █   █ ██  █   █   █     █   █ █   █ █     
█████ ████  █   █  █   █     ████    ████  █   █ █ █ █   █   ████  ████  █   █  ███  
█   █ █     █   █  █   █             █     █   █ █  ██   █   █     █  █  █   █     █ 
█   █ █████ ████  ███ ███            █      ███  █   █   █   █████ █   █  ███  ████  
*/

/*
- NOM. PROGRAMA: Punto-3.c
- NOM. ALUMNO: Medina Juan Gabriel
- DESCRIPCION: No es un programa, es un analisis de un codigo.
- REVISION: [NINGUNA]
*/

#include <stdio.h>
#include <stdlib.h>

typedef float Real;
typedef Real* ApReal;

int main()
{
    /*
    a#- 

    */
    Real temperatura;
    ApReal ApTemperatura;

    ApTemperatura=(float*)malloc(sizeof(float));
    *ApTemperatura= 5.5;
    temperatura= 3.3;


    return 0;
}