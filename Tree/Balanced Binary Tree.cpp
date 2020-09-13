class Solution {
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int lefth=height(root->left);
        int righth=height(root->right);
        if(abs(lefth-righth)>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
