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

Node* insertBST(Node*root, int val){
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }

    return root;
    
    
}

Node* searchBST(Node*root, int key){
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == key)
    {
        return root;
    }
    if (root->data < key)
    {
        return searchBST(root->right, key);
    }
    else{
        
        return searchBST(root->left, key);
    }
    
}

void inorder(Node*root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}


int main(){
    Node*root = NULL;
    root = insertBST(root, 3);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,1);
    insertBST(root,5);
    insertBST(root,8);
    insertBST(root,4);
    insertBST(root,6);

    if (searchBST(root, 9) == NULL)
    {
        cout<<"key doesn't exist";
    }
    else{
        cout<<"key exists";
    }
    
    

    return 0;
}