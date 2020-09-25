class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int h=0;
        for(int i=0;i<root->children.size();i++){
            h=max(h,maxDepth(root->children[i]));
        }
        return h+1;
    }
};
