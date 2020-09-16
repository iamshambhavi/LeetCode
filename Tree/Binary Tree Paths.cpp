class Solution {
public:
    void dfs(TreeNode* root, vector<string>&v, string s){
        if(!root)
            return;
        if(!root->left&&(!root->right)){
            v.push_back(s);
            s="";
            return;
        }
        if(root->left)
        dfs(root->left,v,s+"->"+to_string(root->left->val));
        if(root->right)
        dfs(root->right,v,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector<string>v;
        string s;
        dfs(root,v,s+to_string(root->val));
        return v;
    }
};
