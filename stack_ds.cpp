#include <iostream>
#include <cstdbool>

using namespace std;

#define MAX_LENGTH 101

class Stack
{
    private:
        int data[MAX_LENGTH];
        unsigned int top = -1, count_list = 0;

    public:
        bool _is_full();
        bool _is_empty();
        int _size();
        void display();
        void push(int item);
        int pop();
        int peek();

};

int main(void)
{
    Stack stack_ds;
    int pop_val, peek_val;

    try{
        stack_ds.push(1);
        stack_ds.push(2);
        stack_ds.push(3);
        stack_ds.push(4);
        stack_ds.push(5);

        stack_ds.display();

        pop_val = stack_ds.pop();
        printf("Pop Value: %d\n", pop_val);

        stack_ds.display();

        peek_val = stack_ds.peek();
        printf("Peek Value: %d\n", peek_val);

        stack_ds.display();
    }
    catch(const char* error){
        cerr << "Exception Caught: " << error << endl;
    }

    return 0;
}

// check list is full
bool Stack::_is_full(){
    return this->top == MAX_LENGTH -1;
}

// check list is full
bool Stack::_is_empty(){
    return this->top == -1;
}

// list size
int Stack::_size(){
    return count_list;
}

// display data
void Stack::display()
{
    if(this->count_list == 0)
        throw "Empty List.\n";
    else
    {
        printf("\nData: ");
        for(int i = 0; i < this->_size(); i++)
            printf("%d ", this->data[i]);

        printf("\n\n");
    }
}

// push method
void Stack::push(int item)
{
    if(this->_is_full()){
        throw "Stack Overflow.\n";
    }else{
        this->top += 1;
        this->data[this->top] = item;
        this->count_list++;

        cout << item << " Item Successfully Added" << endl;
    }
}

// pop method
int Stack::pop()
{
    int pop_item;

    if(this->_is_empty()){
        throw "Stack is Empty.!\n";
    }else{
        pop_item = this->data[this->top];
        this->top -= 1;
        this->count_list--;
    }

    return pop_item;
}

// peek method
int Stack::peek()
{
    int peek_item;

    if(this->_is_empty()){
        throw "Peek Value. Stack is Empty.!\n";
    }else{
        peek_item = this->data[this->top];
    }

    return peek_item;
}
