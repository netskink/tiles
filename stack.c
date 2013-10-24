#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"


stack_t  STACK;

void empty_stack(stack_t *pStack) {
    pStack->size = 0;
}


// returns zero when stack is empty
int stack_not_empty(stack_t *pStack) {
    return (pStack->size);
}

void dump_stack(stack_t *pStack) {
	while(pStack->size != 0) {
		printf("%d %c\n",(int)pStack->size,pop(pStack));
	}
}

void push(stack_t *pStack, char chBuffer) {

    if (pStack->size == STACKSIZE) {
        fputs("Error: stack overflow!!!\n", stderr);
		dump_stack(pStack);
        abort();
    } else {
        //pStack->items[pStack->size++] = x;
		pStack->items[pStack->size++]=chBuffer;
	}
}


char pop(stack_t *pStack) {

    if (pStack->size == 0){
        fputs("Error: stack underflow!!!\n", stderr);
        abort();
    } else {
        return pStack->items[--pStack->size];
	}
}
