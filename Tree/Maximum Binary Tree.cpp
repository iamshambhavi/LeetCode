class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r) {
        if(l>=r)
            return NULL;
        int maxi=l;
        for(int i=l+1;i<r;i++){
            if(nums[maxi]<nums[i])
                maxi=i;
        }
        TreeNode* node=new TreeNode(nums[maxi]);
        node->left=constructMaximumBinaryTree(nums,l,maxi);
        node->right=constructMaximumBinaryTree(nums,maxi+1,r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums,0,nums.size());
    }
};
