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
     TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE)
    {
        if(preS > preE)return nullptr;
        int rootData = preorder[preS];
        int rootIndex = -1;
        for(int i = inS; i <= inE; i++)
        {
            if(inorder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }
        int lInS = inS;
        int lInE = rootIndex - 1;
        int lPreS = preS + 1;
        int lPreE = lInE - lInS + lPreS;
        int rInS = rootIndex + 1;
        int rInE = inE;
        int rPreS = lPreE + 1;
        int rPreE = preE;
        TreeNode* root = new TreeNode(rootData);
        root->left = build(preorder,inorder,lPreS,lPreE,lInS,lInE);
        root->right = build(preorder,inorder,rPreS,rPreE,rInS,rInE);
        return root;
    }
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
