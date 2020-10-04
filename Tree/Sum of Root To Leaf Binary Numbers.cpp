class Solution {
public:
    int sum=0,ans=0;
    void dfs(TreeNode*root){
        if(!root)
            return;
        int temp=sum;
        sum=(sum<<1)|root->val;
        if(!root->left&&!root->right){
            ans+=sum;
        }
        dfs(root->left);
        dfs(root->right);
        sum=temp;
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
