class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            swap(front->left,front->right);
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        return root;
    }
};
