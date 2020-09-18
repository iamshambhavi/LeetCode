class Solution {
public:
    int sum=0;
    void dfs(TreeNode* root, int L, int R){
        if(!root)
            return;
        if(root->val>=L&&root->val<=R)
            sum+=root->val;
        if(root->val>L)
            rangeSumBST(root->left,L,R);
        if(root->val<R)
            rangeSumBST(root->right,L,R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root,L,R);
        return sum;
    }
};
