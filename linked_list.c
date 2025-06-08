#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

NODO* node_init(int valor){ //inicializar un nodo
NODO* nodo = (NODO*)malloc(sizeof(NODO)); //se reserva un puntero a un nodo
if (nodo == NULL) {                       //si no se puede, sale de la funcion
    printf("Error al asignar memoria.\n");
    return NULL;
}
nodo->dato = valor; //si logra reservar memoria, guarda el valor solicitado 
nodo->siguiente = NULL; //de momento no necesitamos más nodos
return nodo;
}

void destroy_node(NODO* n){
    free(n);
}

void linked_list_init(LISTA* lista, int valor_inicial) {//recibe un puntero a una lista
    lista->cabeza = node_init(valor_inicial); //crea el primer nodo de la lista

    if (lista->cabeza == NULL) {
        printf("Error al inicializar la lista.\n");
    }
}

int linked_list_append(int data, LISTA* lista ){//recibe el dato y el puntero a lista
    NODO* nuevo=node_init(data);//crea un nuevo nodo
    if(nuevo == NULL){
        return -1;
    }
    if ( lista->cabeza==NULL){
        lista->cabeza=nuevo; //si es el primer elemento, se guarda como cabeza
    }
    else{
        NODO* actual=lista->cabeza;//si no, se recorre la lista en busca del ultimo
        while(actual->siguiente!=NULL){//al encontrar el que apunte a null, se modifica este
            actual=actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    return 0;
}

int linked_list_prepend(int data, LISTA* lista){
    NODO* nuevo=node_init(data);//crea un nuevo nodo
    if(nuevo == NULL){ //devuelve -1 si no puede crear el nodo
        return -1;
    }

    nuevo->siguiente= lista->cabeza; //este nuevo nodo apunta a la cabeza de la lista
    lista->cabeza = nuevo; //se guarda el nodo como la nueva cabeza de la lista
    return 0;
}

int linked_list_remove(int data, LISTA* lista) {
    if (lista->cabeza == NULL) {// si la lista está vacía, no hay nada que eliminar
        return -1;
    }
    NODO* actual = lista->cabeza;// empezamos por la cabeza
    NODO* anterior = NULL;
    
    while (actual != NULL && actual->dato != data) { //recorre la lista, guardando el nodo con el dato y el anterior
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {//si llegamos al final y no encontramos el dato, retorna-1
        return -1;
    }

    if (anterior == NULL) {//si el nodo a eliminar el la cabeza
        lista->cabeza = actual->siguiente; //el siguiene pasa a ser la nueba cabeza
    } else {
        //en cualquier otro caso el bucle termina porque encontró el dato
        anterior->siguiente = actual->siguiente; //hacemos que el anterior apunte al siguiente
    }

    
    destroy_node(actual);// Liberamos la memoria del nodo

    return 0;
}

int linked_list_contains(int data, LISTA* lista){
    if (lista->cabeza == NULL) {// si la lista está vacía, no hay nada que buscar
        return 0;
    }
    NODO* actual = lista->cabeza;// empezamos por la cabeza
    int nodo_encontrado = 0;
    while (actual != NULL ) { //recorre la lista,  
        if (actual->dato==data){
            nodo_encontrado=1;
            break;
        }
        actual = actual->siguiente;

    }

    return nodo_encontrado;
}

unsigned int linked_list_size(LISTA* lista){
    unsigned int tamano=0;
    if (lista->cabeza == NULL) {// si la lista está vacía retorna 0
        return tamano;
    }
    NODO* actual = lista->cabeza;// empezamos por la cabeza
    while (actual != NULL ) { //recorre la lista,  
        tamano++;         //suma al contador
        actual = actual->siguiente;  //avanza

    }

    return tamano;
}

void linked_list_print(LISTA* lista){
    if (lista->cabeza == NULL) {
       return;
    }
    NODO* actual = lista->cabeza;// empezamos por la cabeza
    while (actual != NULL ) { //recorre la lista,  
        printf("%d\n", actual->dato);
        actual = actual->siguiente;  //avanza
    }
}

void destroy_list(LISTA* lista) {
    NODO* actual = lista->cabeza;
    while (actual != NULL) {
        NODO* siguiente = actual->siguiente;  // Guarda el siguiente nodo
        destroy_node(actual);      // Libera el nodo actual
        actual = siguiente;  // Avanza al siguiente
    }
    lista->cabeza = NULL;  // Por seguridad, establecemos la cabeza como NULL
free(lista);

}