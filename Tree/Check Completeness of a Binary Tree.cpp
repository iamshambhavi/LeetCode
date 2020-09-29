class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool flag=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(!front)
                flag = true;
            else {
                if(flag)
                    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};
