class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>v;
        stack<TreeNode*>s,ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* top=s.top();
            s.pop();
            v.push_back(top->val);
            if(top->left)
                s.push(top->left);
            if(top->right)
                s.push(top->right);
            
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
