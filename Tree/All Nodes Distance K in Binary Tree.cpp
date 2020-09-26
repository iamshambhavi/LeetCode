class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>m;
    unordered_set<TreeNode*>visited;
    void dfs(TreeNode* root, TreeNode*target){
        if(!root||root==target)
            return;
        if(root->left){
            m[root->left]=root;
            dfs(root->left,target);
        }
        if(root->right){
            m[root->right]=root;
            dfs(root->right,target);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,target);
        vector<int>v;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty()&&k>=0){
            int size=q.size();
            while(size--){
                TreeNode*front=q.front();
                q.pop();
                int val=front->val;
                visited.insert(front);
                if(k==0)
                    v.push_back(val);
                if(front->left&&(!visited.count(front->left)))
                    q.push(front->left);
                if(front->right&&(!visited.count(front->right)))
                    q.push(front->right);
                if(m[front]&&(!visited.count(m[front])))
                    q.push(m[front]);
            }
            k--;
        }
        return v;
    }
};
