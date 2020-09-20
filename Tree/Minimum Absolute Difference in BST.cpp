class Solution {
public:
    int prev=-1,minimum=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        getMinimumDifference(root->left);
        if(prev!=(-1))
            minimum=min(minimum,abs(root->val-prev));
        prev=root->val;
        getMinimumDifference(root->right);
        return minimum;
    }
};
