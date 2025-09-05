/*4. Escribir un programa que permita ingresar un número entero positivo y luego, mediante una
función recursiva, muestre el número de forma invertida. Ej.: 123 - 321.
 Pista: Para invertir un número, se puede usar el principio de extraer dígitos
mediante divisiones sucesivas por 10: el último dígito se obtiene con numero % 10
(resto de la división por 10), y el número sin ese último dígito se obtiene con
numero / 10 (cociente de la división por 10). En la función recursiva, cada llamada
procesa un dígito y continúa con el número reducido*/
#include <stdio.h>

// Función recursiva para mostrar el número invertido
void mostrarInvertido(int n) {
    if (n == 0)  // caso base
        return;

    printf("%d", n % 10);   /*imprimir último dígito*/
    mostrarInvertido(n / 10); /*llamada recursiva con el número reducido*/
}

int main() {
    int numero;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("El numero debe ser positivo.\n");
        return 1;
    }

    printf("Numero invertido: ");
    if (numero == 0) {
        printf("0"); /*si se ingresa 0*/
    } else {
        mostrarInvertido(numero);
    }
    printf("\n");

    return 0;
}
