#include <stdio.h>
#include <locale.h> 

#define MAX 20

int solicitarCantidad();
void cargarVector(int vector[], int cantidad);
void mostrarVector(int vector[], int cantidad);
int sumarElementos(int vector[], int cantidad);
float calcularPromedio(int suma, int cantidad);
int buscarMayor(int vector[], int cantidad);
int buscarMenor(int vector[], int cantidad);
void contarParesImpares(int vector[], int cantidad);

int main(){

    setlocale(LC_CTYPE, "Spanish"); //Sirve para poner ñ, ó, etc.

    int vectorEnteros[MAX];
    int cantidad, suma, mayor, menor;
    float promedio;

    cantidad = solicitarCantidad();

    cargarVector(vectorEnteros, cantidad);

    mostrarVector(vectorEnteros, cantidad);

    suma = sumarElementos(vectorEnteros, cantidad);
    promedio = calcularPromedio(suma, cantidad);
    mayor = buscarMayor(vectorEnteros, cantidad);
    menor = buscarMenor(vectorEnteros, cantidad);

    printf("\n--- RESULTADOS ---\n");
    printf("La suma de todos los elementos es: %d\n", suma);
    printf("El promedio de los valores es: %.2f\n", promedio);
    printf("El mayor elemento del vector es: %d\n");
    printf("El menor elemento del vector es: %d\n");

    contarParesImpares(vectorEnteros, cantidad);

    return 0;
}

int solicitarCantidad(){
    int cantidad;
    do {
        printf("Ingrese la cantidad de elementos del vector (entre 1 y %d): ", MAX);
        scanf("%d", &cantidad);

        if(cantidad < 1 || cantidad > MAX){
            printf("Error: La cantidad ingresada no es valida. Intente nuevamente.\n");
          }
    } while (cantidad < 1 || cantidad > MAX);

    return cantidad;
}

void cargarVector(int vector[], int cantidad){
    int i;
    printf("\n--- CARGA DE DATOS ---\n");
    for (i=0; i<cantidad; i++){
        printf("Ingrese el valor para la posicion %d: ", i+1);
        scanf("%d", &vector[i]);
    }
}

void mostrarVector(int vector[], int cantidad){
    int i;
    printf("\n--- ELEMENTOS DEL VECTOR ---\n");
    for (i = 0; i < cantidad; i++){
        printf("%d", vector[i]);
    }
    printf("\n");
}

int sumarElementos(int vector[], int cantidad){
    int i;
    int suma = 0;
    for (i = 0; i < cantidad; i++){
        suma += vector[i];
    }
    return suma;
}

float calcularPromedio(int suma, int cantidad){
    return(float) suma / cantidad;
}

int buscarMayor(int vector[], int cantidad){
    int i;
    int mayor = vector[0];
    for (i = 1; i < cantidad; i++){
        if (vector[i] > mayor){
            mayor = vector[i];
        }
    }
    return mayor;
}

int buscarMenor(int vector[], int cantidad){
    int i;
    int menor = vector[0];

    for (i=1; i<cantidad; i++){
        if (vector[i] < menor){
            menor = vector[i];
        }
    }
    return menor;
}

void contarParesImpares(int vector[], int cantidad){
    int i;
    int pares = 0;
    int impares = 0;

    for (i=0; i < cantidad; i++){
        if (vector[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    printf("Cantidad de numeros pares: %d\n", pares);
    printf("Cantidad de numeros impares: %d\n", impares);
}
