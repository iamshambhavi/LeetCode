class Solution {
public:
    int ans=1;
    int depth(TreeNode* root){
        if(!root)
            return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        ans=max(ans,left+right+1);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans-1;
    }
};
