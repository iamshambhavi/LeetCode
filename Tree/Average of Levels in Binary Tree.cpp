class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            double size=q.size();
            double avg=0;
            for(int i=0;i<size;i++){
                TreeNode*front=q.front();
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                avg+=front->val;
            }
            v.push_back(avg/size);
        }
        return v;
    }
};
