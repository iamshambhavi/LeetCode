class Solution {
public:
    unordered_map<int,int>m;
    void dfs(TreeNode*root){
        if(!root)
            return;
        m[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int maxValue=INT_MIN;
        for(auto x:m){
            if(x.second>maxValue){
                maxValue=x.second;
            }
        }
        vector<int>v;
        for(auto x:m){
            if(x.second==maxValue){
                v.push_back(x.first);
                x.second-=1;
            }   
        }
        return v;
    }
};
