class Solution {
public:
    pair<int,int> robbery(TreeNode* root){
        if(!root)
            return {0,0};
        auto left=robbery(root->left);
        auto right=robbery(root->right);
        pair<int,int>ans={0,0};
        ans.second=left.first+right.first;
        ans.first=max(ans.second,left.second+right.second+root->val);
        return ans;
        
    }
    int rob(TreeNode* root) {
        return robbery(root).first;
    }
};
