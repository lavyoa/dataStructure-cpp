//
//  stack implementation with linked list
//

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    
    top = newNode;
}

void Pop()
{
    if(top == NULL)
        return;
    
    Node* temp = top;
    top = top->next;
    delete temp;
}

Node* Top()
{
    return top;
}

bool IsEmpty()
{
    if(top == NULL)
        return 1;
    
    return 0;
}

void Print()
{
    Node* temp = top;
    printf("stack is ...\n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    printf("%d \n", IsEmpty());
    Push(3); Print();
    Push(4); Print();
    Pop(); Print();
    Push(6); Print();
    Push(7); Print();
    printf("%d \n", IsEmpty());
    return 0;
}
