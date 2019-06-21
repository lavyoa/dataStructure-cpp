// stack - array Implementation

#include <iostream>
#define MAX_SIZE 3

class Stack
{
private:
    int A[MAX_SIZE];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    
    void Push(int x)
    {
        if (top >= MAX_SIZE-1)
        {
            printf("Error : size of the stack is not enough!\n");
            return;
        }
        A[++top] = x;
    }
    
    int Top()
    {
        return A[top];
    }
    
    void Pop()
    {
        if(top == -1)
        {
            printf("Error : stack is already empty!");
            return;
        }
        top--;
    }
    
    
    bool IsEmpty()
    {
        if(top == -1)
            return true;
        
        return false;
    }
    
    void Print()
    {
        for(int i=0; i<=top; ++i)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    
};

int main(int argc, const char * argv[]) {
    
    Stack stack;
    stack.Push(3); stack.Print();
    stack.Push(2); stack.Print();
    stack.Push(5); stack.Print();
    stack.Push(8); stack.Print();
    stack.Pop(); stack.Print();
    stack.Pop(); stack.Print();
    stack.Pop(); stack.Print();
    stack.Pop(); stack.Print();
    printf("\n");
    return 0;
}

