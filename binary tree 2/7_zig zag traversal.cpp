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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector <vector<int>> ans;
        if(!root) 
            return ans;
        queue <TreeNode*> q;
        q.push(root);
        int count = 1; 
        while(!q.empty())
        {
            int n = q.size();
            vector <int> v;
            
            while(n--)
            {
                root=q.front();
                q.pop();
                v.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            if(count%2==0) // we want reverse the list at alternate order
                reverse(v.begin(),v.end());
            ans.push_back(v);
            count++;
        }
        
        return ans;
         
    }
};
