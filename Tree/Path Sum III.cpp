class Solution {
    int dfs(TreeNode*root,int sum){
        if(!root)
            return 0;
        if(sum==root->val)
            return 1+dfs(root->left,sum-root->val)+dfs(root->right,sum-root->val); 
        else
            return dfs(root->left,sum-root->val)+dfs(root->right,sum-root->val);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*front=q.front();
                q.pop();
                count+=dfs(front,sum);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
        }
        return count;
    }
};
