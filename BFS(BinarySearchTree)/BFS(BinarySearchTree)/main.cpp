
// BFS(BinarySearchTree)
// Binary Search Traversal Algorithm - BreadthFisrtSearch(Level Order Search)
// 각 노드의 레벨 순서대로 탐색.
// Time Complexity : O(N)
// Space Complexity : best - O(1) / worst - O(N)

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

void BFS(Node* root)
{
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* cur = q.front();
        cout << cur->data << " ";
        q.pop();
        
        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);
    }
}

Node* Insert(Node* rootNode, char data)
{
    if(rootNode == NULL)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        
        rootNode = newNode;
        return newNode;
    }
    
    if(data <= rootNode->data) rootNode->left = Insert(rootNode->left, data);
    else rootNode->right = Insert(rootNode->right, data);
    return rootNode;
}


int main(int argc, const char * argv[]) {

    Node* root = NULL;
    root = Insert(root,'M'); root = Insert(root,'B');
    root = Insert(root,'Q'); root = Insert(root,'Z');
    root = Insert(root,'A'); root = Insert(root,'C');
    
    BFS(root);
    return 0;
}
