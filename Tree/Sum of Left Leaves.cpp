class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleft) {
        if(!root)
            return 0;
        if(!root->left&&(!root->right)){
            if(isleft)
                return root->val;
            return 0;
        }
            return sumOfLeftLeaves(root->left, true)+sumOfLeftLeaves(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode*root){
        bool isleft=false;
        return sumOfLeftLeaves(root,isleft);
    }
    
};
