class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN;
            while(size--){
                TreeNode* front=q.front();
                q.pop();
                if(front->val>maxi)
                    maxi=front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            v.push_back(maxi);
        }
        return v;
    }
};
