class Solution {
    TreeNode* dfs(TreeNode*root, TreeNode*node){
        if(!root)
            return NULL;
        
        if(root->right)
        node=dfs(root->right, node);

        if(root->left)
        node=dfs(root->left, node);

        root->right=node;
        root->left=NULL;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode*node=NULL;
        dfs(root,node);
    }
};
