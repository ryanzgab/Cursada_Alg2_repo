#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef char tString[MAX];

typedef struct{
	int codProducto;
	tString descripcion;
	float precioUnitario;
}tProducto;

typedef struct nodoProducto{
	tProducto producto;
	struct nodoProducto* siguiente;
}tListaProductos;

tProducto ingresarProducto();
void inicializarLista();
void insertarProducto(tProducto);
void mostrarProductos(tListaProductos*);

tListaProductos* productos;

int main(){
	inicializarLista();
	
	tProducto nuevoProducto=ingresarProducto();
	insertarProducto(nuevoProducto);
	mostrarProductos(productos);
	
	// insertamos otro producto
	nuevoProducto=ingresarProducto();
	insertarProducto(nuevoProducto);
	mostrarProductos(productos);
	
	return 0;
}

tProducto ingresarProducto(){
	tProducto producto;
	printf("\nIngrese c%cdigo del producto: ", 162);
	scanf("%d", &producto.codProducto);
	printf("Ingrese descripci%cn del producto: ", 162);
	fflush(stdin);
	scanf("%[^\n]s", &producto.descripcion);
	printf("Ingrese precio unitario del producto: ");
	scanf("%f", &producto.precioUnitario);
	return producto;
}

void inicializarLista(){
	productos = NULL;
	printf("\n**************************************************\n");
	printf("            Lista de productos inicializada");
	printf("\n**************************************************\n");
}

void insertarProducto(tProducto pProducto){
	tListaProductos* nuevoProducto;
	nuevoProducto = (tListaProductos*) malloc(sizeof(tListaProductos));
	nuevoProducto->producto = pProducto;
	nuevoProducto->siguiente = productos;
	productos = nuevoProducto;
	printf("\n**************************************************");
	printf("\n\tProducto insertado:");
	printf("\n\tC%cdigo: %d", 162, pProducto.codProducto);
	printf("\n\tDescripci%cn: %s", 162, pProducto.descripcion);
	printf("\n\tPrecio Unitario: $%.2f", pProducto.precioUnitario);
	printf("\n**************************************************\n");
}

void mostrarProductos(tListaProductos* pListaProductos){
	tListaProductos* listaAux = pListaProductos;
	printf("\n\n--------------------------------------------------\n");
	printf("                   Lista Productos");
	while(listaAux!=NULL){
		printf("\n--------------------------------------------------");
		printf("\n\tC%cdigo: %d", 162, listaAux->producto.codProducto);
		printf("\n\tDescripci%cn: %s", 162, listaAux->producto.descripcion);
		printf("\n\tPrecio Unitario: $%.2f", listaAux->producto.precioUnitario);
		printf("\n--------------------------------------------------");
		listaAux = listaAux->siguiente;
	}
	printf("\n");
}

