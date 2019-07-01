/*
 Binary Search Tree(BST) Implementation using Recursion
 BTS : a binary tree in which for each node,
        value of all the nodes in left subtree is lesser and value of all the nodes in right subtree is greater.

 Time Complexity of BST is...
 - Insert : O(logN)
 - Remove : O(logN)
 - Search : O(logN)
 */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

Node* Insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}


int main(int argc, const char * argv[]) {
    
    Node* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 9);
    if(Search(root, 9))
        cout << "found! " << endl;
    else cout << "Not found.. " << endl;
    return 0;
}
