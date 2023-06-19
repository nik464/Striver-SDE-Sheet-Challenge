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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>answer;


        queue<TreeNode*>q; // i created queue

        if(!root)
        return answer;

        q.push(root);


        while(!q.empty())
        {
            int sz=q.size();
            
             vector<int>res;
        

            while(sz--)
             {

                 TreeNode* t =q.front();
                 res.push_back(t->val);
                 q.pop();

                 if(t->left)
                 q.push(t->left);

                 if(t->right)
                 q.push(t->right);
             }

             answer.push_back(res);

        }
     return answer;

    }
};