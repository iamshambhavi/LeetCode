class Solution {
public:
    int max1=INT_MIN,max2=INT_MIN;
    void dfs(TreeNode* root,int val){
        if(!root)
            return;
        if(max1<abs(root->val-val))
            max1=abs(root->val-val);
        dfs(root->left,val);
        dfs(root->right,val);
    }
    void nodes(TreeNode* root){
        if(!root)
            return;
        dfs(root,root->val);
        if(max1>max2)
            max2=max1;
        nodes(root->left);
        nodes(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        nodes(root);
        return max2;
    }
};
