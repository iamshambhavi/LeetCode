class Solution {
public:
    set<int>s;
    void dfs(TreeNode* root){
        if(!root)
            return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        dfs(root);
        if(s.size()>=2){
            auto t=s.begin();
            t++;
            return *t;
        }
        return -1;
    }
};
