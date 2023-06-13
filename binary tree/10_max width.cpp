#include <bits/stdc++.h>
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        
        int ans=0;
        
        while(!q.empty())
        {
            
         int size= q.size();
        int mmin= q.front().second;
          
        int first, last;
        for(int i=0;i<size;i++)     
        {
            int cur_id= q.front().second -mmin;
         
            
            if(i==0) first= cur_id;
            if(i==size-1) last=cur_id;
            
               TreeNode* t=q.front().first;
            q.pop();
            
            if(t->left)
                q.push({t->left, 2*cur_id+1});
             
             if(t->right)
                 q.push({t->right, 2*cur_id+2});
            
        }
            
        ans = max(ans, last-first+1);    
            
        }
        
    return ans;
    }
};
