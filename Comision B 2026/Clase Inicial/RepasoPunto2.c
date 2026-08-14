#include <stdio.h>
#include <locale.h>

#define MAX 10

int solicitarDimension(char tipo[]);
void cargarMatriz(int matriz[][MAX], int filas, int columnas);
void mostrarMatriz(int matriz[][MAX], int filas, int columnas);
int sumarElementos(int matriz[][MAX], int filas, int columnas);
float calcularPromedio(int suma, int filas, int columnas);
int buscarMayor(int matriz[][MAX], int filas, int columnas);
void sumarFilas(int matriz[][MAX], int filas, int columnas);
void sumarColumnas(int matriz[][MAX], int filas, int columnas);

int main(){
	
	setlocale(LC_CTYPE, "Spanish");
	    
	int matrizEnteros[MAX][MAX];
	int filas, columnas, suma, mayor;
	float promedio;
	char opcion;
	
	printf("--- CONFIGURACIÓN DE LA MATRIZ ---\n");
	filas = solicitarDimension("filas");
	columnas = solicitarDimension("columnas");

	cargarMatriz(matrizEnteros, filas, columnas);
	
	do {
		printf("\n================ MENÚ PRINCIPAL ================\n");
		printf("a) Mostrar la matriz completa.\n");
		printf("b) Calcular y mostrar la suma de todos los elementos.\n");
		printf("c) Calcular y mostrar el promedio de los elementos.\n");
		printf("d) Mostrar el mayor valor almacenado.\n");
		printf("e) Mostrar la suma de cada fila.\n");
		printf("f) Mostrar la suma de cada columna.\n");
		printf("g) Finalizar el programa.\n");
		printf("================================================\n");
		printf("Ingrese una opción: ");
		
		scanf(" %c", &opcion);
		
		switch(opcion){
			case 'a':
			case 'A':
				mostrarMatriz(matrizEnteros, filas, columnas);
				break;
			case 'b':
			case 'B':
				suma = sumarElementos(matrizEnteros, filas, columnas);
				printf("\nLa suma de todos los elementos es: %d\n", suma);
				break;
			case 'c':
			case 'C':
				sumarElementos(matrizEnteros, filas, columnas);
				promedio = calcularPromedio(suma, filas, columnas);
				printf("\nEl promedio de los elementos es: %.2f\n", promedio);
				break;
			case 'd':
			case 'D':
				mayor = buscarMayor(matrizEnteros, filas, columnas);
				printf("\nEl mayor valor almacenado es: %d\n", mayor);
				break;
			case 'e':
			case 'E':
				sumarFilas(matrizEnteros, filas, columnas);
				break;	
			case 'f':
			case 'F':
				sumarColumnas(matrizEnteros, filas, columnas);
				break;
			case 'g':
			case 'G':
				printf("\nSaliendo del programa...");
				break;
		}
		if(opcion != 'g' && opcion != 'G'){
			fflush(stdin);
			system("pause");
			system("cls");
		}
		
	} while (opcion != 'g' && opcion != 'G');
		
		return 0;
}

int solicitarDimension(char tipo[]){
	int dimension, validacion;
	
	do{
	  printf("Ingrese la cantidad de %s (entre 1 y %d): ", tipo, MAX);
	  validacion = scanf("%d", &dimension);
	  
	  if(validacion !=1 || dimension < 1 || dimension > MAX){
	  	printf("Error: Valor no válido. Intentá nuevamente!\n");
	  	fflush(stdin);
	  	dimension=0;
	  }
	}while (dimension < 1 || dimension > MAX);
	
	return dimension;
}

void cargarMatriz(int matriz[][MAX], int filas, int columnas) {
    int i, j, validacion;
    
    printf("\n--- CARGA DE DATOS ---\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            
            do {
                printf("Ingrese el valor para la posicion [Fila %d][Columna %d]: ", i + 1, j + 1);
                validacion = scanf("%d", &matriz[i][j]);

                if (validacion != 1) {
                    printf("Error: Ingreso no valido. Solo se permiten números.\n");
                    fflush(stdin);
                }
            } while (validacion != 1);
        }
    }
}

void mostrarMatriz(int matriz[][MAX], int filas, int columnas){
	int i, j;
	printf("\n--- MATRIZ CARGADA ---\n");
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			printf("%d \t", matriz[i][j]);
		}
		printf("\n");
	}
}

int sumarElementos(int matriz[][MAX], int filas, int columnas){
	int i, j;
	int suma = 0;
	for (i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			suma += matriz[i][j];
		}
	}
	return suma;
}

float calcularPromedio(int suma, int filas, int columnas){
	int totalElementos = filas * columnas;
	return (float) suma / totalElementos;
}

int buscarMayor(int matriz[][MAX], int filas, int columnas){
	int i, j;
	int mayor = matriz[0][0];
	
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			if(matriz[i][j]>mayor){
				mayor = matriz[i][j];
			}
		}
	}
	return mayor;
}

void sumarFilas(int matriz[][MAX], int filas, int columnas){
	int i, j, suma;
	printf("\n--- SUMA POR FILAS ---\n");
	for(i=0; i<filas; i++){
		suma=0;
		for(j=0; j<columnas; j++){
			suma += matriz[i][j];
		}
		printf("Suma de la fila %d: %d\n", i+1, suma);
	}
}

void sumarColumnas(int matriz[][MAX], int filas, int columnas){
	int i, j, suma;
	printf("\n--- SUMA POR COLUMNAS ---\n");
	for(j=0; j<columnas; j++){
		suma = 0;
		for(i=0; i<filas; i++){
			suma += matriz[i][j];
		}
		printf("Suma de la columna %d: %d\n", j+1, suma);
	}
}
