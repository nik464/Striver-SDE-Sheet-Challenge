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
     int sum(TreeNode* root, int& answer){
         
        if(root == NULL)
            return 0;
        
        int l = sum(root -> left, answer);
        int r = sum(root -> right, answer);
        
        int temp = max(max(l, r) + root -> val, root -> val);
        int ans = max(temp, l + r + root -> val);
        answer =  max(answer, ans);
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
         int answer = INT_MIN;
        sum(root, answer);
        return answer;
    }
};
