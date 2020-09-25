class Solution {
public:
    vector<int>v;
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        for(auto x:root->children)
            postorder(x);
        v.push_back(root->val);
        return v;
    }
};
