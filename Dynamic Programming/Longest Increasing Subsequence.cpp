class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++){
                if(nums[i-1]>nums[j-1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int maxi=dp[0];
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
