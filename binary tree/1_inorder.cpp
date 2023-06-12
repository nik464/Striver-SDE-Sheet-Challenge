class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>inorder;
        if(root==NULL)
       return inorder;
        
        stack<TreeNode*>st;
        
        while(root!=NULL || !st.empty())
        {
            
            while(root)
            {
                   st.push(root);
                
                   root=root->left;
            }
            
            
           root= st.top();
            st.pop();
            
            inorder.push_back(root->val);
            root=root->right;
        }
        
        
     return inorder;   
    }
};
