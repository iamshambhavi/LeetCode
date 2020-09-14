class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        s.push(root);
        while(true){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(--k==0)
                return root->val;
            root=root->right;
        }
    }
};
