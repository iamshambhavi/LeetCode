class Solution {
    TreeNode* bstFromPreorder(vector<int>& preorder,int si,int ei){
        if(si>ei)
            return NULL;
        TreeNode*root=new TreeNode(preorder[si]);
        int leftEnd=si;
        for(int i=si+1;i<=ei;i++){
            if(preorder[si]<preorder[i])
                break;
            leftEnd=i;
        }
        root->left=bstFromPreorder(preorder,si+1,leftEnd);
        root->right=bstFromPreorder(preorder,leftEnd+1,ei);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder,0,preorder.size()-1);
    }
};
