#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//procedimiento inicial
void pruebaA();
//puntero a Utilizar
bool * apuntBool;

int main(){
    pruebaA();
    return 0;
}

void pruebaA(){

    bool sexo;
    sexo = true;

    apuntBool = &sexo;

    printf("\nEl valor de verdad es:"); printf(*apuntBool ? "true":"false"); //manera de imprimir un Bool
    printf("\nSu contenido es: %p\n", apuntBool);
    printf("\nSu direccion es: %p\n", &apuntBool);
}