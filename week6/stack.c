#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    // 이곳을 채워주세요!
    if(isEmpty(stack))
	{
    	return -9999;	
	}
    int tmp = stack->array[stack->top];
    stack->top = stack->top-1;
    return tmp;
}

int peek(Stack* stack) {
    // 이곳을 채워주세요!
    if(isEmpty(stack)){
    	printf("this is empty\n");
    	return; 
	}
    return stack->array[stack->top];
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}
