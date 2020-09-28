class Solution {
public:
    TreeNode* node=new TreeNode(0);
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        root->left=NULL;
        node->right=root;
        node=root;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode*ans=node;
        inorder(root);
        return ans->right;
    }
};
