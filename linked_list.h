#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct NODO{ //definimos el tipo nodo
    int dato;   //un nodo tiene un dato
    struct NODO* siguiente; //y un puntero al siguiente nodo
}NODO;

typedef struct LISTA{
    NODO* cabeza;
}LISTA;

//crear un nodo
NODO* node_init(int valor);

//destruir un nodo
void destroy_node(NODO *n);



//inicializar la lista
void linked_list_init(LISTA* lista, int valor_inicial);

// Agregar un elemento al final de la lista
// 0: éxito, -1: error
int linked_list_append(int data, LISTA* lista);

// Agregar un elemento al inicio de la lista
// 0: éxito, -1: error
int linked_list_prepend(int data, LISTA* lista);

// Elimina el primer elemento que coincide con el dato proporcionado
// 0: éxito, -1: error (elemento no encontrado)
int linked_list_remove(int data, LISTA* lista);

// Encontrar un elemento en la lista
// 1: éxito, 0: error (elemento no encontrado)
int linked_list_contains(int data, LISTA* lista);

// Regresa el tamaño de la lista
unsigned int linked_list_size(LISTA* lista);

// Imprimir todos los elementos de la lista enlazada
void linked_list_print(LISTA* lista);

void destroy_list(LISTA* lista);

#endif // LINKED_LIST_H