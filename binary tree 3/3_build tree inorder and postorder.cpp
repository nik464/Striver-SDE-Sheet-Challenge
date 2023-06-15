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
     TreeNode*build(vector<int>& post,int posi,int poei,vector<int>& inod,int insi,int inei){
        
        // if(insi > inei) return nullptr;
        
        if(posi > poei) return NULL;
        
        int idx=insi;
        
        while(inod[idx] != post[poei]) idx++;
        
        int noOfE=idx-insi;
        
        TreeNode* root=new TreeNode(post[poei]);
        
        root->left=build(post,posi,posi+noOfE-1,inod,insi,idx-1);
        
        root->right=build(post,posi+noOfE,poei-1,inod,idx+1,inei);
        
        return root;   
        
    }
    
    TreeNode* buildTree(vector<int>& inod, vector<int>& post) {
        
        int n=inod.size();
        
        TreeNode*root=build(post,0,n-1,inod,0,n-1);
        
        return root;
    }
};
