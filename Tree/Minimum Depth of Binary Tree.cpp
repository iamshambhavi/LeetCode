class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int minleft=minDepth(root->left);
        int minright=minDepth(root->right);
        if(!root->left)
            return minright+1;
        if(!root->right)
            return minleft+1;
        return min(minleft,minright)+1;
    }
};
