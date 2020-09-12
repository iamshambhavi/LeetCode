class Solution {
public:
    TreeNode* buildTree(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int lps=ps;
        int lis=is;
        int i=is;
        while(inorder[i]!=root->val)
            i++;
        int lie=i-1;
        int lpe=lps+lie-lis;
        root->left=buildTree(postorder, lps, lpe, inorder, lis, lie);
        int rps=lpe+1;
        int rpe=pe-1;
        int ris=i+1;
        int rie=ie;
        root->right=buildTree(postorder, rps, rpe, inorder, ris, rie);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
