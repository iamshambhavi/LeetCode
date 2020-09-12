class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int lps=ps+1;
        int lis=is;
        int i=is;
        while(inorder[i]!=root->val)
            i++;
        int lie=i-1;
        int lpe=lps+lie-lis;
        root->left=buildTree(preorder, lps, lpe, inorder, lis, lie);
        int rps=lpe+1;
        int rpe=pe;
        int rie=ie;
        int ris=i+1;
        root->right=buildTree(preorder, rps, rpe, inorder, ris, rie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
