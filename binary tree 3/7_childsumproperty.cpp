#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 


int isSumValidated(Node* root)
    {
        if(root==NULL) return 1;
        if(!root->left && !root->right) return 1;
        int leftChild = root->left?root->left->data:0;
        int rightChild = root->right?root->right->data:0;
        return root->data == leftChild+rightChild && isSumValidated(root->left)&&isSumValidated(root->right);
    }
    int isSumProperty(Node *root)
    {
        return isSumValidated(root);
    }
