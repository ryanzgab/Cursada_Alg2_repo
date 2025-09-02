/*4. Una empresa de delivery de comida necesita un sistema para gestionar pedidos mediante una lista
enlazada. Para cada pedido se almacena: numeroPedido (entero), nombreCliente (cadena), direccion
(cadena), telefono (cadena), montoTotal (flotante), estadoPedido (cadena: "Pendiente", "Preparando",
"En camino", "Entregado"), tiempoEstimado (entero en minutos).
El sistema debe calcular automáticamente:
- Costo de envío: $500 si el monto es menor a $3000, gratis si es mayor o igual.
- Tiempo estimado: Base de 30 minutos + 5 minutos por cada $1000 del monto.
- Prioridad: "Alta" si el monto > $5000, "Normal" en caso contrario.
Funcionalidades requeridas:
a) Crear nuevo pedido (calcular automáticamente costo envío, tiempo y prioridad).
b) Cambiar estado de un pedido (buscar por número de pedido).
c) Eliminar pedidos entregados.
d) Buscar pedidos por cliente.
e) Mostrar todos los pedidos según la prioridad que se desee consultar.
f) Mostrar el total de pedidos según el estado que se desee consultar.
g) Calcular y mostrar el monto promedio de pedidos pendientes.
h) Listado de pedidos con prioridad alta que estén "En camino".
i) Cliente con mayor cantidad de pedidos.
j) Tiempo promedio estimado de pedidos no entregados.
Además:
k) Aplicar descuento del 10% a pedidos de un cliente específico.
l) Marcar como "Entregado" todos los pedidos "En camino" de más de 60 minutos.
Implementar un menú principal completo y asegurar la correcta liberación de memoria al finalizar el
programa. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCARD 50

typedef char tString[MAXCARD];

typedef struct 
{
    int numPedido, tiempEstimado;
    tString nameCliente, direccionCliente, telfCliente, estadoPedido;
    float montoTotal;
}tPedido;

typedef struct nodo
{
    tPedido pedido;
    struct nodo * siguiente;
}tListaPedido;


tPedido ingresarPedido();
void AnalizarEstadoPedido();

void inicializarLista(tListaPedido**);
void insertarPedido(tListaPedido**,tPedido);
void insertarPrimerPedido(tListaPedido**,tPedido);
void insertarPedidoalPrincipio(tListaPedido**, tPedido);
void insertarPedidoCliente();
void calcularPedidos();
void mostrarDatosPedido(tPedido);
void eliminarPedidosEntregados(); 
void mostrarListaPedido(tListaPedido*);

bool listaVacia(tListaPedido*);
float promPendientes();
int promTiempoNoEntregados();

int main()
{
    tListaPedido* Pedido;
    
    int opcion;
    inicializarLista(&Pedido);
    while(opcion == 0)
    {
        tPedido pPedido = ingresarPedido();
        insertarPedido(&(Pedido), pPedido);
        printf("Desea Seguir Ingresando ?:");
        scanf("%d", &opcion);
    }

    mostrarListaPedido(Pedido);
    return 0;
}

void inicializarLista(tListaPedido** pListaPedido)
{
    *pListaPedido = NULL;

    printf("\n-----------------------------------------------------");
	printf("\n                LISTA INICIALIZADA");
	printf("\n-----------------------------------------------------\n");
}

bool listaVacia(tListaPedido* pListaPedido)
{
    return (pListaPedido == NULL);
}




tPedido ingresarPedido()
{
    tPedido pedido;
    printf("-N°de pedido: ");
    scanf("%d",&pedido.numPedido); /*En Caso de que sea Entero o Flotante se usa el "&" antes de agregar la variable de la estructura*/
    
    fflush(stdin);
    printf("-Nombre del Cliente: ");
    scanf("%[^\n]",pedido.nameCliente); /*En caso de ser Cadena de caracteres no se utiliza "&"*/
    
    fflush(stdin);
    printf("-Direccion del Cliente: ");
    scanf("%[^\n]",pedido.direccionCliente);

    fflush(stdin);
    printf("-Telefono(+54): ");
    scanf("%[^\n]",pedido.telfCliente);
    
    fflush(stdin);    
    printf("-Monto del Pedido: ");
    scanf("%f",&pedido.montoTotal);

    fflush(stdin);    
    printf("-Estado del Pedido: ");
    scanf("%[^\n]",pedido.estadoPedido);

    return pedido;
}



void insertarPedido(tListaPedido** pListaPedido, tPedido pPedido)
{
    if(listaVacia(*pListaPedido))
    {
        insertarPrimerPedido(&(*pListaPedido), pPedido);
    }else
    {
        insertarPedidoalPrincipio(&(*pListaPedido), pPedido);
    }
}

void insertarPrimerPedido(tListaPedido** pListaPedido, tPedido pPedido)
{
    tListaPedido *nuevoPedido;
    nuevoPedido = (tListaPedido*)malloc(sizeof(tListaPedido));
    nuevoPedido->pedido = pPedido;
    nuevoPedido->siguiente = NULL;
    *pListaPedido = nuevoPedido;

    printf("\n-----------------------------------------------------");
	printf("\n                PEDIDO A%cADIDO",165);
	printf("\n-----------------------------------------------------\n");

}

void insertarPedidoalPrincipio(tListaPedido** pListaPedido, tPedido pPedido)
{
    tListaPedido *nuevoPedido;
    nuevoPedido = (tListaPedido*)malloc(sizeof(tListaPedido));
    nuevoPedido->pedido = pPedido;
    nuevoPedido->siguiente = *pListaPedido;
    *pListaPedido = nuevoPedido;
    printf("\n-----------------------------------------------------");
	printf("\n                PEDIDO A%cADIDO",165);
	printf("\n-----------------------------------------------------\n");

}

void mostrarDatosPedido(tPedido pPedido)
{
    printf("-N°de pedido: %d\n",pPedido.numPedido);
    printf("-Nombre del Cliente: %s\n",pPedido.nameCliente);
    printf("-Direccion del Cliente: %s\n", pPedido.direccionCliente);
    printf("-Telefono(+54): %s\n", pPedido.telfCliente);
    printf("-Monto del Pedido: %.2f\n", pPedido.montoTotal);
    
    if(pPedido.montoTotal > 3000)
    {
        printf("--Coste del Envio: $500");
    }
    if(pPedido.montoTotal <= 3000)
    {
        printf("--ENVIO GRATIS\n");
    }
    printf("-Estado del Pedido: %s\n", pPedido.estadoPedido);
}

void mostrarListaPedido(tListaPedido* pListaPedido)
{
    if(listaVacia(pListaPedido))
    {
        printf("\n-----------------------------------------------------");
	    printf("\n                LISTA VACIA");
	    printf("\n-----------------------------------------------------\n");
    }else
    {
        tListaPedido *pAuxiliar = pListaPedido;
        printf("\n-----------------------------------------------------");
	    printf("\n               PEDIDOS YA");
	    printf("\n-----------------------------------------------------\n");
        while (pAuxiliar != NULL)
        {
            mostrarDatosPedido(pAuxiliar->pedido);
            printf("\n-----------------------------------------------------\n");
            pAuxiliar = pAuxiliar->siguiente;
        }
    }
}