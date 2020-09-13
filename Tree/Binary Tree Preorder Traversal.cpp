class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>v;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* front=s.top();
            s.pop();
            v.push_back(front->val);
            if(front->right)
                s.push(front->right);
            if(front->left)
                s.push(front->left);
        }
        return v;

    }
};
