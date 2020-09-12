class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(nums, start, mid-1);
        root->right=sortedArrayToBST(nums, mid+1, end);
        return root;
    
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);   
    }
};
