class Solution {
public:
    unordered_map<string,vector<TreeNode*>>m;
    string dfs(TreeNode*root){
        if(!root)
            return "";
        string ans="("+dfs(root->left)+to_string(root->val)+dfs(root->right)+")";
        m[ans].push_back(root);
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root)
            return {};
        dfs(root);
        vector<TreeNode*>v;
        for(auto x:m){
            if(x.second.size()>1)
                v.push_back(x.second[0]);
        }
        return v;
    }
};
