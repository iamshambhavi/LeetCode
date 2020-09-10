class Solution {
public:
    bool isValidBST(TreeNode* root, long greater, long smaller){
        if(!root)
            return true;
        if(root->val>=greater)
            return false;
        if(root->val<=smaller)
            return false;
        return isValidBST(root->left,root->val,smaller)&&isValidBST(root->right,greater,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
};
