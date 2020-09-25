
class Solution {
public:
    vector<int>v;
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        v.push_back(root->val);
        for(auto x:root->children){
            preorder(x);
        }
        return v;
    }
};
