class Solution {
public:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(!root1&&(!root2))
            return true;
        if(!root1||(!root2))
            return false;
        if(root1->val!=root2->val)
            return false;
        return isSymmetric(root1->right, root2->left)&&isSymmetric(root1->left, root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};
