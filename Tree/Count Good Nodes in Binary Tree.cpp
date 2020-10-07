class Solution {
public:
void find(TreeNode* root, int mx,int &cnt){
    if(root){
        if(root->val>=mx){
            cnt++;
            mx=root->val;
        }
        find(root->left,mx,cnt);
        find(root->right,mx,cnt);
    }
}
int goodNodes(TreeNode* root) {
    int cnt=0;
    find(root,INT_MIN,cnt);
    return cnt;
}
};
