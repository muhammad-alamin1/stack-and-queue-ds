# Circular Queue implementation in Python

class Queue:
    def __init__(self, n):
        self.n = n
        self.data = [None] * n
        self.head = -1
        self.tail = -1
    
    def print_queue(self):
        print("Queue: ", end=" ")
        for i in range(len(self.data)):
            print(self.data[i], end=" ")
    
    def is_empty(self):
        if(self.head == -1):
            return True
        return False
    
    def is_full(self):
        if((self.tail + 1) % self.n == self.head):
            return True
        return False
    
    def enqueue(self, item):
        if self.is_full():
            raise IndexError("Sorry! Queue is Full.!")
        else:
            if self.is_empty():
                self.head = 0
                self.tail = (self.tail + 1) % self.n
                self.data[self.tail] = item
            else:
                self.tail = (self.tail + 1) % self.n
                self.data[self.tail] = item
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("Sorry! Queue is empty.!")
        else:
            item = self.data[self.head]
            self.head = (self.head + 1) % self.n
            
            if self.head == (self.tail + 1) % self.n:
                self.head = -1
                self.tail = -1
                
            return item

if __name__ == "__main__":
    try:
        queue = Queue(5)
    
        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)
        queue.enqueue(4)
        queue.enqueue(5)
        queue.print_queue()
        
        res = queue.dequeue()
        print("Dequeue: ", res)
        
        queue.enqueue(6)
        
        queue.print_queue()
    except IndexError as err:
        print(err)