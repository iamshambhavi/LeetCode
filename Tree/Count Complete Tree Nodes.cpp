class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode*front=q.front();
                q.pop();
                if(front->left&&front->right){
                    q.push(front->left);
                    q.push(front->right);
                    count+=2;
                }   
                else if(front->left){
                    q.push(front->left);
                    count+=1;
                }    
            }
        }
        return count;
    }
};
