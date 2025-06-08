#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

void test_stack() {
    Stack s;
    Stack *ptr_s=&s;
    printf("Probando la implementación de 'stack')\n");
    stack_init(ptr_s);

    printf("Agregando 100 elementos...\n");
    for (int i = 1; i <= 100; i++) {
        if (stack_push(i, ptr_s) == -1) {
            printf("Error en push %d\n", i);
        }
    }

    printf("Tamaño: %u (esperado: 100)\n", stack_size(ptr_s));
    printf("Stack lleno? %d (esperado: 1)\n", stack_is_full(ptr_s));

    printf("Intentando un push más...\n");
    printf("Resultado del push: %d (esperado: -1)\n", stack_push(101, ptr_s));

    printf("Sacando 5 elementos...\n");
    for (int i = 0; i < 5; i++) {
        printf("Popped %d (esperado: %d)\n", stack_pop(ptr_s), 100 - i);
    }

    printf("Tamaño: %u (esperado: 95)\n", stack_size(ptr_s));
    printf("Stack vacío? %d (esperado: 0)\n", stack_is_empty(ptr_s));

    printf("Vaciando el stack...\n");
    while (!stack_is_empty(ptr_s)) {
        stack_pop(ptr_s);
    }

    printf("Tamaño: %u (esperado: 0)\n", stack_size(ptr_s));
    printf("Stack vacío? %d (esperado: 1)\n", stack_is_empty(ptr_s));

    printf("Pop de un stack vacío...\n");
    printf("Popped: %d (esperado: -1)\n", stack_pop(ptr_s));
}

void test_linked_list() {
    printf("\nTesting Linked List implementation...\n");
    LISTA* lista= malloc(sizeof(LISTA));
    linked_list_init(lista, 10);

    printf("Agregando 10, 20, 30...\n");
    linked_list_append(20, lista);
    linked_list_append(30, lista);

    printf("Agregando 5 al inicio...\n");
    linked_list_prepend(5, lista);

    printf("Lista (debería ser 5, 10, 20, 30): \n");
    linked_list_print(lista);

    printf("Tamaño: %u (esperado: 4)\n", linked_list_size(lista));
    printf("¿Contiene a 20? %d (esperado: 1)\n", linked_list_contains(20, lista));
    printf("¿Contiene a 99? %d (esperado: 0)\n", linked_list_contains(99, lista));

    printf("Quitando 20...\n");
    linked_list_remove(20, lista);

    printf("Lista (debería ser 5, 10, 30): \n");
    linked_list_print(lista);
    printf("Quitando 99...\n");
    printf("Resultado: %d (esperado: -1)\n", linked_list_remove(99, lista));
    printf("Tamaño: %u (esperado: 3)\n", linked_list_size(lista));

    destroy_list(lista);
}

int main() {
    test_stack();
    test_linked_list();
    return 0;
}