//
//  main.cpp
//  linkedList
//
//  Created by 김지연 on 2019. 6. 18..
//  Copyright © 2019년 김지연. All rights reserved.
//

#include <iostream>
#include <stdio.h>

struct Node
{
    int data;
    Node* link;
};

Node* header = NULL;

void InsertAtEnd(int value)
{
    Node* temp = NULL;

    if(header == NULL)
    {
        temp = new Node();
        temp->data = value;
        temp->link = NULL;
    
        header = temp;
    }
    else
    {
        temp = new Node();
        temp->data = value;
        temp->link = NULL;
        
        Node* temp1 = header;
        while((*temp1).link != NULL)
        {
            temp1 = (*temp1).link;
        }
        temp1->link = temp;
    }
}

void InsertAtBeginning(int value)
{
    Node* temp1 = new Node;
    temp1->data = value;
    temp1->link = header;

    header = temp1;
}

void InsertAt(int value, int n)
{
    Node* temp1 = new Node();
    temp1->data = value;
    temp1->link = NULL;
    
    if(n==1)
    {
        temp1->link = header;
        header = temp1;
        return;
    }
    
    Node* temp2 = header;
    for(int i=0; i<n-2; ++i)
    {
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}

void DeleteAt(int n)
{
    Node* temp1 = header;

    if (n==1)
    {
        header = temp1->link;
        delete temp1;
        return;
    }
    
    for(int i=0; i<n-2; ++i)
        temp1 = temp1->link;
    
    Node* temp2 = temp1->link;
    temp1->link = temp2->link;
    delete temp2;
}

void ReverseIteratively()
{
    Node* prev = NULL;
    Node* next = NULL;
    Node* cur = header;
    
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    header = prev;
}

void ReverseRecursively(Node* cur)
{
    if(cur == NULL)
        return;
    
    if(cur->link == NULL)
    {
        header = cur;
        return;
    }
    ReverseRecursively(cur->link);
    cur->link->link = cur; // Node* q = cur->link; q->link = cur; 구문과 동일 
    cur->link = NULL;
}

void Print()
{
    Node* temp = header;
    printf("List is...\n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {

    InsertAt(2,1);
    InsertAt(3,2);
    InsertAt(4,1);
    InsertAt(5,2);
    InsertAtBeginning(0);
    InsertAtEnd(9);
    Print(); // 0 4 5 2 3 9
    ReverseIteratively();
    Print(); // 9 3 2 5 4 0
    ReverseRecursively(header);
    Print(); // 0 4 5 2 3 9
    return 0;
}
