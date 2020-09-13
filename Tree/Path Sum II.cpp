class Solution {
    vector<vector<int>> vec;
    vector<int>v;
    void dfs(TreeNode*root, int sum){
        if(!root)
            return;
        v.push_back(root->val);
        if(root->val==sum&&(!root->left)&&(!root->right))
            vec.push_back(v);
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return vec;
    }
};
