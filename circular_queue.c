/*  implement circular queue
    Queue rulls: FIFO(first in first out)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 5

bool is_full();
bool is_empty();
void print_queue();
void enqueue(int item);
int dequeue();

int Queue[MAX_LENGTH];
int front = 0, rear = -1, total_items = 0;

int main(void)
{
    int dequeue_res;

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    print_queue();

    dequeue_res = dequeue();
    dequeue_res = dequeue();
    dequeue_res = dequeue();
    printf("Dequeue: %d\n", dequeue_res);

    enqueue(60);
    enqueue(70);

    print_queue();

    return 0;
}

// check queue is full
bool is_full()
{
    if(total_items == MAX_LENGTH)
        return true;
    else
        return false;
}

// check queue is empty
bool is_empty()
{
    if(rear == -1)
        return true;
    return false;
}

// display queue
void print_queue()
{
    unsigned int i;

    printf("Queue: \n");
    for(i = 0; i < MAX_LENGTH; i++)
        printf("%d ", Queue[i]);
    printf("\n");
}

// enqueue
void enqueue(int item)
{
    if(is_full()){
        printf("Sorry.! Queue is full.\n");
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % MAX_LENGTH;
    Queue[rear] = item;
    total_items++;
}

// dequeue
int dequeue()
{
    int dequeue_item;

    if(is_empty()){
        printf("Sorry.! Queue is Empty.\n");
        exit(EXIT_FAILURE);
    }

    dequeue_item = Queue[front];
    Queue[front] = -1;
    front = (front + 1) % MAX_LENGTH;
    total_items--;

    return dequeue_item;
}
