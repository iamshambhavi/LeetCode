class Solution {
public:
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return NULL;
        int left=height(root->left);
        int right=height(root->right);
        if(left==right)
            return root;
        else{
            if(left>right)
                return subtreeWithAllDeepest(root->left);
            else
                return subtreeWithAllDeepest(root->right);
        }
    }
};
