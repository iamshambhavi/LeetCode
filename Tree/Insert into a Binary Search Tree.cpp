class Solution {
public:
    TreeNode* insertIntoBSTs(TreeNode* root, TreeNode* newNode){
        if(!root)
            return newNode;
        if(root->val>newNode->val)
            root->left=insertIntoBSTs(root->left,newNode);
        else
            root->right=insertIntoBSTs(root->right,newNode);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* currNode=root;
        TreeNode* newNode=new TreeNode(val);
        return insertIntoBSTs(root,newNode);
        if(!currNode)
            return newNode;
        while(currNode){
            if(currNode->val>newNode->val){
                if(currNode->left){
                    currNode=currNode->left;
                    continue;
                }
                currNode->left=newNode;
                break;
            }
            else{
                if(currNode->right){
                    currNode=currNode->right;
                    continue;
                }
                currNode->right=newNode;
                break;
            }
        }
        return root;
    }
};
