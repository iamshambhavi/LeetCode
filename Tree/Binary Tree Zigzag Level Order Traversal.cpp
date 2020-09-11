class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        if(!root)
            return vec;
        queue<TreeNode*>q;
        q.push(root);
        bool toggle=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            if(!toggle)
                reverse(v.begin(),v.end());
            vec.push_back(v);
            toggle? toggle=false:toggle=true;
        }
        return vec;
    }
};
