class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>vec;
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            while(size--){
                Node*front=q.front();
                q.pop();
                for(auto x:front->children){
                    q.push(x);
                }
                v.push_back(front->val);
            }
            vec.push_back(v);
        }
        return vec;
    }
};
