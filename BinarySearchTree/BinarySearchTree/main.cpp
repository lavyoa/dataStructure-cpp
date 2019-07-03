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

Node* Find(Node* root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data <= root->data)
    {
        return Find(root->left, data);
    }
    else
    {
        return Find(root->right, data);
    }
}

/* 해당 트리가 이진탐색트리인지 검사
 (이진탐색트리 조건 : 기준노드의 왼쪽에 위치한 노드의 값이 항상 작고 오른쪽에 위치한 노드의 값이 기준보다 커야 함)I
 Time Complexity : O(N)
 또다른 방법 : InOrder Search를 통해 출력되는 node의 data가 바로 이전에 출력된 data보다 큰 지 검사하는 방법. Time Complexity O(N)으로 동일.
 */
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

/* 특정 데이타의 노드를 삭제
 case 1. 해당 노드의 자식이 없는 경우 - 바로 삭제
 case 2. 해당 노드의 자식이 하나만 있는 경우 - 노드 삭제, 해당 노드의 부모노드가 삭제된 노드의 자식노드를 가리키도록 변경
 case 3. 해당 노드의 자식이 두 개 있는 경우 - 해당 노드의 왼쪽에서 최대값을 가진 노드 or 오른쪽에서 최소값을 가진 노드의 값을 복사.
                                      복사한 노드 제거(재귀)
*/
Node* FindMax(Node* root)
{
    while(root->right != NULL)
        root = root->right;
    
    return root;
}

Node* Delete(Node* root, int data)
{
    if(root == NULL)
        return root;
    
    if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete (root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL) // case 1.
        {
            delete root;
        }
        else if (root->left == NULL) // case 2.
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            
        }
        else if (root->right == NULL) // case 2.
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else // case 3.
        {
            Node* max = FindMax(root->left);
            root->data = max->data;
            root->left = Delete(root->left, max->data);
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    
    Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 7);
    root = Insert(root, 6);
    root = Insert(root, 9);
    root = Insert(root, 15);
    root = Insert(root, 12);
    root = Insert(root, 11);
    root = Insert(root, 13);
    root = Insert(root, 19);
    root = Insert(root, 17);
    root = Insert(root, 16);
    root = Insert(root, 18);
    root = Insert(root, 25);

    if(Search(root, 19))
        cout << "found! " << endl;
    else cout << "Not found.. " << endl;
    
    cout << "Is Binary tree? " << IsBinarySearchTree(root) << endl;
    
    Delete(root, 19);
    if(Search(root, 19))
        cout << "found! " << endl;
    else cout << "Not found.. " << endl;
    
    return 0;
}
