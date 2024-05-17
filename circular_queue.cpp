// circular queue

#include <iostream>

using namespace std;

#define MAX_LENGTH 5

class Queue
{
    private:
        int data[MAX_LENGTH];
        int head, tail, q_size;
    public:
        int queue_size();
        bool is_full();
        bool is_empty_queue();
        void display();
        void set();
        void enqueue(int item);
        int dequeue();
};

int main(void)
{
    Queue que;
    que.set();

    int result;

    try{
        que.enqueue(10);
        que.enqueue(20);
        que.enqueue(30);
        que.enqueue(40);
        que.enqueue(50);

        que.display();

        result = que.dequeue();
        cout << "Dequeue: " << result << endl;

        que.display();

        que.enqueue(60);


        que.display();

    }catch(const char* error){
        cout << error << endl;
    }

    return 0;
}

// set private data
void Queue::set(){
    this->head = -1;
    this->tail = -1;
    this->q_size = 0;
}

// check queue is full
bool Queue::is_full(){
    if(this->q_size == MAX_LENGTH)
        return true;
    else
        return false;
}

// check queue is empty
bool Queue::is_empty_queue(){
    if(this->tail == -1)
        return true;
    return false;
}

// queue size
int Queue::queue_size(){
    return this->q_size;
}

// display queue
void Queue::display()
{
    unsigned int i;

    if (this->is_empty_queue()) {
        cout << "Queue is empty" << endl;
        return;
    }

    i = this->head;
    cout << "Queue: ";
    for(int j = 0; j < this->q_size; j++){
        cout << this->data[j] << " ";
        i = (i + 1) % MAX_LENGTH;
    }

    cout << endl;
}

// enqueue
void Queue::enqueue(int item)
{
    if(this->is_full())
        throw "Sorry! Queue is Full.\n";
    else{
        if(this->is_empty_queue())
            this->head = 0;

        this->tail = (this->tail + 1) % MAX_LENGTH;
        this->data[this->tail] = item;
        this->q_size += 1;
    }
}

// dequeue
int Queue::dequeue()
{
    int item;

    if(this->is_empty_queue())
        throw "Sorry! Queue is empty.\n";
    else{
        item = this->data[this->head];
        this->data[this->head] = -1;
        this->head = (this->head + 1) % MAX_LENGTH;
        this->q_size--;

        if(this->q_size == 0){
            this->head = -1;
            this->tail = -1;
        }
    }

    return item;
}
