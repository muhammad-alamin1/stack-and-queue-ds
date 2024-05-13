# stack ds implementation

class Stack:
    def __init__(self):
        self.data = []
    
    def push(self, item):
        self.data.append(item)
    
    def pop(self):
        if self.is_empty():
            raise IndexError("Pop! Stack is Empty.!")
        return self.data.pop()
    
    def peek(self):
        if self.is_empty():
            raise IndexError("Peek! Stack is Empty.!")
        item = self.data[-1]    # return last index data without remove list
        return item
    
    def is_empty(self):
        if len(self.data) == 0:
            return True
        return False
    
    def size(self):
        return len(self.data)
    

if __name__ == "__main__":
    stack = Stack()
    
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    
    # display all data before pop
    for i in range(stack.size()):
        print("Data ", stack.data[i])
    
    pop_res = stack.pop()
    print("Pop Data: ", pop_res)
    
    peek_res = stack.peek()
    print("Peek Data: ", peek_res)
    
    for i in range(stack.size()):
        print("Data ", stack.data[i])
