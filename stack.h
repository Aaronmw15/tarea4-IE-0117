#ifndef STACK_H
#define STACK_H

typedef struct { //define el tipo stack, con un tamano de 100 elementos
int arr[100];
int top; // Índice del elemento superior de la pila
} Stack;

// Inicializar stack con un máximo de 100 elementos
void stack_init(Stack *s);//recibe un puntero a un stack

// Agregar un entero al stack
// 0: éxito, -1: stack lleno
int stack_push(unsigned int data, Stack *s);

// Saca un elemento del stack
// Regresa el entero: éxito, -1: stack está vacío
int stack_pop(Stack *s);

// Regresa el tamaño del stack
unsigned int stack_size(Stack *s); //recibe el puntero al stack

// 1: lleno, 0: no lleno
int stack_is_full(Stack *s);

// 1: vacío, 0: no vacío
int stack_is_empty(Stack *s);

#endif // STACK_H