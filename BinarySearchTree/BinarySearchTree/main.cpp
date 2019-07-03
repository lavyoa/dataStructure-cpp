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

// 해당 트리가 이진탐색트리인지 검사
// (이진탐색트리 조건 : 기준노드의 왼쪽에 위치한 노드의 값이 항상 작고 오른쪽에 위치한 노드의 값이 기준보다 커야 함)
// Time Complexity : O(N)
// 또다른 방법 : InOrder Search를 통해 출력되는 node의 data가 바로 이전에 출력된 data보다 큰 지 검사하는 방법. Time Complexity O(N)으로 동일.
bool IsBSTUtil(Node* root, int min, int max)
{
    if(root == NULL)
        return true;
    
    if(root->data < min || root->data >max)
        return false;
    
    if(IsBSTUtil(root->left, min, root->data) &&
       IsBSTUtil(root->right, root->data, max))
        return true;
    
    return false;
}


// 해당 트리가 이진탐색트리인지 검사
bool IsBinarySearchTree(Node* root)
{
    if(root == NULL)
        return false;
    
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}


int main(int argc, const char * argv[]) {
    
    Node* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 11);
    root = Insert(root, 20);
    root = Insert(root, 9);
    if(Search(root, 9))
        cout << "found! " << endl;
    else cout << "Not found.. " << endl;
    
    cout << "Is Binary tree? " << IsBinarySearchTree(root) << endl;
    return 0;
}
