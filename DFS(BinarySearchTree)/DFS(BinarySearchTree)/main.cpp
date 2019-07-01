//  DFS(BinarySearchTree)
//  Preorder, Inorder, Postorder
// Time Complexity : O(N) - 모든 노드를 한번씩 방문.
// Space Complxity : O(H) - 트리의 height만큼 재귀함수 호출되므로.
//                   best : O(logN) (퍼펙트 바이너리 트리일 때)
//                   worst : O(N) (링크드리스트 처럼 연결되어 있을 때)

#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root, char data)
{
    if(root == NULL)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = NULL; newNode->right = NULL;
        
        root = newNode;
        return newNode;
    }
    
    if(data <= root->data)
        root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    
    return root;
}

// Data(Root) - Left - Right 순서대로 탐색
void Preorder(Node* root)
{
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Left - Data(Root) - Right 순서대로 탐색
void Inorder(Node* root)
{
    if(root == NULL)
        return;
    
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Left -Right - Data(Root) 순서대로 탐색
void Postorder(Node* root)
{
    if(root == NULL)
        return;
    
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main(int argc, const char * argv[]) {

    Node* root = NULL;
    root = Insert(root,'M'); root = Insert(root,'B');
    root = Insert(root,'Q'); root = Insert(root,'Z');
    root = Insert(root,'A'); root = Insert(root,'C');
    cout << "Postorder..." << endl;
    Postorder(root);
    cout << endl;
    cout << "Preorder..." << endl;
    Preorder(root);
    cout << endl;
    cout << "Inorder..." << endl;
    Inorder(root);
}
