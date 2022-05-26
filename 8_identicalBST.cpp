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

bool isIdenticalBST(Node* root1, Node* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else {
        // Condition 1..
        bool cond1 = root1->data == root2->data;
        // Condition 2..
        bool cond2 = isIdenticalBST(root1->left, root2->left);
        // Condition 3..
        bool cond3 = isIdenticalBST(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
        
    }
    
    
    
    
}

int main(){
    Node*root1 = new Node(8);
    root1->left = new Node(6);
    root1->right = new Node(9);
    root1->left->right = new Node(7);
    root1->right->right = new Node(11);

    Node*root2 = new Node(8);
    root2->left = new Node(6);
    root2->right = new Node(9);
    root2->left->right = new Node(7);
    root2->right->right = new Node(11);

    if (isIdenticalBST(root1, root2))
    {
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Not Identical"<<endl;
    }
    

    return 0;
}