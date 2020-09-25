class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        deque<pair<TreeNode*,size_t>>q;
        q.push_back({root,1});
        size_t maxi=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                if(size==q.size()-1)
                    maxi=max(maxi,q.back().second-q.front().second+1);  
                pair<TreeNode*,size_t>front=q.front();
                q.pop_front();
                if(front.first->left)
                    q.push_back({front.first->left,front.second*2-1});
                if(front.first->right)
                    q.push_back({front.first->right,front.second*2});
            }
        }
        return maxi;
    }
};
