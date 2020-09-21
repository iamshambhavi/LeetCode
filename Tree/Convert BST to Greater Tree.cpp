class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return NULL;
        stack<TreeNode*>s;
        TreeNode* node=root;
        int rightsum=0;
        while(node!=NULL||(!s.empty())){
            while(node!=NULL){
                s.push(node);
                node=node->right;
            }
            node=s.top();
            s.pop();
            node->val+=rightsum;
            rightsum=node->val;
            node=node->left;
        }
        return root;
    }
};
