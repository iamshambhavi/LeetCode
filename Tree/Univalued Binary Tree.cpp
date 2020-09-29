class Solution {
public:
    bool ans=true;
    void dfs(TreeNode*root,int &v){
        if(!root)
            return;
        if(root->val!=v){
            ans=false;
            return;
        }
        dfs(root->left,v);
        dfs(root->right,v);
    }
    bool isUnivalTree(TreeNode* root) {
        int v=root->val;
        dfs(root,v);
        return ans;
    }
};
