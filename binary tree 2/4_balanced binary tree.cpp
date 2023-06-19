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
    
    int checkbalanced(TreeNode* root)
    {
        
        if(root==NULL)
            return 0;
        
        
        int ls=checkbalanced(root->left);
        int rs= checkbalanced(root->right);
        
        if(ls!=-1 && rs!=-1 )
        {
            if(abs(ls-rs)>1)
                return -1;
            
            else 
                return 1+max(ls,rs);
        }
        
       return -1 ;
        
    }
            
            
    
    bool isBalanced(TreeNode* root) {
        if(checkbalanced(root)==-1)
            return false;
        else
        return true;
    }
};