
//  doublyLinkedList implementation

#include <iostream>
#include <stdio.h>

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* header = NULL;

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}

void InsertAtHead(int data)
{
    Node* newNode = GetNewNode(data);
    
    if(header == NULL)
    {
        header = newNode;
        return;
    }
    
    header->prev = newNode;
    newNode->next = header;
    header = newNode;
}

void InsertAtTail(int data)
{
    Node* newNode = GetNewNode(data);
    Node* cur = header;
    
    if(header == NULL)
    {
        header = newNode;
        return;
    }
    
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    newNode->prev = cur;
    cur->next = newNode;
}

void Print()
{
    Node* cur = header;
    printf("List is...\n");
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void PrintReverse()
{
    printf("Reversed List is ...\n");
    Node* cur = header;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
}

int main(int argc, const char * argv[]) {
    
    InsertAtTail(6);
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtTail(5);
    InsertAtTail(7);

    Print();
    PrintReverse();
    return 0;
}


