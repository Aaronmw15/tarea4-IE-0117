#include "stack.h"//importamos stack.h para tener la deficion de stack


void stack_init(Stack *s){//recibe un puntero a un stack            
    s->top = -1;          //inicializa el top en -1 (stack vacío)
}

int stack_push(unsigned int data, Stack *s){ //recibe el puntero al stack y el numero para agregar
    if(s->top<99){    //verifica si el stack tiene espacio
        s->top+=1;     //aumentamos el indice
        s->arr[s->top]=data;   //agrega el valor

        return 0;  //retorne 0 si todo salió bien
    } 
    else{
        return -1; //si el stack está lleno, devuelve error
    }                       
}

int stack_pop(Stack *s){
     if(s->top>-1){    //verifica si el stack no está vacío
        unsigned int data=s->arr[s->top];   //guarda el ultimo valor
        s->top-=1;     //disminuye el indice

        return data;  //retorna el ultimo valor si todo salió bien
    } 
    else{
        return -1; //si el stack está vacío, devuelve error
    }  
}

unsigned int stack_size(Stack *s){//recibe el puntero al stack
    unsigned int tamano= s->top+1; //al empezar a contar desde cero, el tamano es top+1 
    return tamano;
}

int stack_is_full(Stack *s){//recibe el puntero al stack
    int tamano= stack_size(s);//tomamos el tamaño del stack
    if(tamano==100){  //si es 100, está lleno
        return 1;
    } 
    else{
        return 0;
    }
}

int stack_is_empty(Stack *s){
       int tamano= stack_size(s);//tomamos el tamaño del stack
    if(tamano==0){  //si es -1, está vacío 
        return 1;
    } 
    else{         
        return 0;
    } 
}