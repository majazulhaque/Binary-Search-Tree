#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*left, *right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* buildBalancedBST(int arr[], int start, int end){
    if (start > end)
    {
        return NULL;
    }
    
    
    int mid = (start + end)/2;
    Node*root = new Node(arr[mid]);

    root->left = buildBalancedBST(arr, start, mid-1);
    root->right = buildBalancedBST(arr, mid+1, end);

    return root;
}

void printInorder(Node*root){
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    
}
void printpreorder(Node*root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
    
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};

    Node*root = buildBalancedBST(arr, 0, 4);

    printInorder(root);
    cout<<endl;
    printpreorder(root);

    return 0;
}