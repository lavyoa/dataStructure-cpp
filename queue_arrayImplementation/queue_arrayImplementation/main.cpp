// array implementation of Queue

#include <iostream>
#define MAX_SIZE 5

using namespace std;
class Queue
{
private:
    int Q[MAX_SIZE];
    int front;
    int rear;
    
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    
    int Front()
    {
        return Q[front];
    }
    
    void Enqueue(int data)
    {
        if(IsFull())
        {
            cout << "ERROR : Queue is Full!\n";
            return;
        }
        
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        Q[rear] = data;
    }
    
    void Dequeue()
    {
        if (IsEmpty())
        {
            
            return;
        }
        
        // if there's only one element in queue
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return;
        }
        
        front = (front + 1) % MAX_SIZE;
    }
    
    bool IsEmpty()
    {
        if(front == -1 && rear == -1)
            return true;
        return false;
    }
    
    bool IsFull()
    {
        if(IsEmpty())
            return false;
        
        if (rear == (front -1 + MAX_SIZE) % MAX_SIZE)
            return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Queue q;
    cout << "is queue empty? " << q.IsEmpty() << "\n";
    q.Enqueue(1);
    cout << "front : " << q.Front() << "\n";
    q.Enqueue(2);
    q.Dequeue();
    q.Enqueue(8);
    q.Enqueue(3);
    q.Dequeue();
    cout << "front : " << q.Front() << "\n";
    cout << "is full? : " << q.IsFull() << "\n";
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);

    return 0;
}
