class Solution {
public:
    int maxSumPath(TreeNode* root, int &maxSum){
        if(!root)
            return 0;
        int left=maxSumPath(root->left,maxSum);
        int right=maxSumPath(root->right,maxSum);
        int case1=max(max(left,right)+root->val,root->val);
        int case2=max(case1,left+right+root->val);
        maxSum=max(maxSum,case2);
        return case1;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        maxSumPath(root,maxSum);
        return maxSum;
    }
};
