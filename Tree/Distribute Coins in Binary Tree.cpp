class Solution {
public:
    int ans=0;
    int dfs(TreeNode*root){
        if(!root)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        ans+=abs(left)+abs(right);
        return root->val+left+right-1;
    }
    int distributeCoins(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};
