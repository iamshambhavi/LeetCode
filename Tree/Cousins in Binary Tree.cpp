class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return true;
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>m;
        TreeNode* xparent,*yparent;
        bool flag1=false,flag2=false;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* front=q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                    m[front->left]=front;
                }
                if(front->right){
                    q.push(front->right);
                    m[front->right]=front;
                }
                if(front->val==x){
                    flag1=true;
                    xparent=m[front];
                }
                if(front->val==y){
                    flag2=true;
                    yparent=m[front];
                }
            }
            if(flag1&&flag2){
                if(xparent->val!=yparent->val)
                    return true;
            }
            else{
                    xparent=NULL;
                    yparent=NULL;
                    flag1=false;
                    flag2=false;
            }
        }
        return false;
    }
};
