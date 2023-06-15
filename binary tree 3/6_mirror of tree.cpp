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


class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    Node* help(Node* &root){
        if(root==NULL){
            return NULL;
        }
        Node* l=help(root->left);
        Node* r=help(root->right);
        root->left=root->right;
        root->right=l;
    }
    void mirror(Node* node) {
       help(node);
    }
};

