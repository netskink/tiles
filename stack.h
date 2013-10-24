// This is a stack that can store strings of 256 chars per stack element.
// The stack itself can only hold 100 strings.  Since the stack in this
// project holds a single definition and no definition is more than 60 
// lines this is sufficient.

#define STACKSIZE 10000
struct stack {
    size_t size;
    char items[STACKSIZE];
};
typedef struct stack stack_t;

void empty_stack(stack_t *pStack);

int stack_not_empty(stack_t *pStack);

void push(stack_t *pStack, char chBuffer);

char pop(stack_t *pStack);

void dump_stack(stack_t *pStack);
