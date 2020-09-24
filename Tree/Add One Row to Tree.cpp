class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        if(d==1){
            TreeNode*currRoot=new TreeNode(v);
            currRoot->left=root;
            return currRoot;
        }
        while(!q.empty()){
            int size=q.size();
            if(--d==1)
                flag=true;
            else
            	flag=false;
            while(size--){
                TreeNode*front=q.front();
                q.pop();
                if(front->left)
                    q.push(front->left); 
                if(front->right)
                    q.push(front->right);
                if(flag){
                    TreeNode* currLeft=front->left;
                    TreeNode*l=new TreeNode(v);
                    front->left=l;
                    l->left=currLeft;
                }  
                if(flag){
                    TreeNode* currRight=front->right;
                    TreeNode*r=new TreeNode(v);
                    front->right=r;
                    r->right=currRight;
                }
            }
        }
        return root;
    }
};
