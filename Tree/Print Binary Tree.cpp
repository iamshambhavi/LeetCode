class Solution {
public:
    vector<vector<string>>ans;
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    void gogetfilled(TreeNode*root,int row,int l,int r){
        if(!root)
            return;
        ans[row][(l+r)/2]=to_string(root->val);
        gogetfilled(root->left, row+1, l, (l+r)/2);
        gogetfilled(root->right, row+1, (l+r+1)/2, r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root)
            return {};
        int h=height(root);
        ans=vector<vector<string>>(h);
        for(int i=0;i<h;i++)
            ans[i]=vector<string>((1<<h)-1);
        gogetfilled(root,0,0,ans[0].size());
        return ans;
    }
};
