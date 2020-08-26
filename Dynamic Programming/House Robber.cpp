class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        if(n==1)
            return dp[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};