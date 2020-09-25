class Solution {
public:
    int ans=0;
    int helper(TreeNode*root){
        if(!root)
            return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        int arrowLeft=0,arrowRight=0;
        if(root->left&&(root->val==root->left->val))
            arrowLeft=left+1;
        if(root->right&&(root->val==root->right->val))
            arrowRight=right+1;
        ans=max(ans,arrowLeft+arrowRight);
        return max(arrowLeft,arrowRight);
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
};
