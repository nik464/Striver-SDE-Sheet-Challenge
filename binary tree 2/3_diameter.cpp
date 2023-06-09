#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
   int diameter=INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)return 0;
        int leftHeight=helper(root->left);
        int rightHeight=helper(root->right);
        diameter=max(diameter,leftHeight+rightHeight);
        return max(leftHeight,rightHeight)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
    }
};
