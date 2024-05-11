// stack code implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

bool is_full();
bool is_empty();
void push(int arr[], int item);
int peek(int arr[]);
int pop(int arr[]);

int top = -1;

int main(void)
{
    int stack[MAX_SIZE];
    int result, i;

    result = peek(stack);
    printf("Peek Data: %d\n", result);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    result = peek(stack);
    printf("Peek Data: %d\n", result);

    printf("Before Call Pop function Stack Data: ");
    for(i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    result = pop(stack);
    printf("\nPop Data: %d\n", result);
    result = pop(stack);
    printf("Pop Data: %d\n", result);

    printf("After Call Pop function Stack Data: ");
    for(i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    return 0;
}

// push()
void push(int arr[], int item)
{
    if(is_full())
    {
        printf("Stack Overflow.\n");
        // exit(EXIT_FAILURE);
    }else{
        top += 1;
        arr[top] = item;
        printf("Successfully Added item: %d\n", item);
    }
}

// peek() retrieve the top item from the stack without removing it.
int peek(int arr[])
{
    if(is_empty())
    {
        printf("Stack is Empty.\n");
        return -1;
    }
    return arr[top];
}

// pop()
int pop(int arr[])
{
    int value;

    if(is_empty())
    {
        printf("Stack is Empty.\n");
        return -1;
    }else{
        value = arr[top];
        arr[top] = 0;
        top--;
        return value;
    }
}

// if check stack is full
bool is_full(){
    return top == MAX_SIZE - 1;
}

// if check stack is empty
bool is_empty(){
    return top == -1;
}
