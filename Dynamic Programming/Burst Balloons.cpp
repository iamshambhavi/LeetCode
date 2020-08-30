class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int window=1;window<=n;window++){
            for(int left=1;left<=n-window+1;left++){
                int right=left+window-1;
                for(int i=left;i<=right;i++){
                    dp[left][right]=max(dp[left][right],dp[left][i-1]+(nums[left-1]*nums[i]*nums[right+1])+dp[i+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
