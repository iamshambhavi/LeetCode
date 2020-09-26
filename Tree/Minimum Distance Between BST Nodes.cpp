class Solution {
public:
    int mini=INT_MAX,prev=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return 0;
        minDiffInBST(root->left);
        int n=abs(root->val-prev);
        if(mini>n)
            mini=n;
        prev=root->val;
        minDiffInBST(root->right);
        return mini;
    }
};
