class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        size_t dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto x:nums){
                if(x<=i)
                    dp[i]+=dp[i-x]; //included x and then see if i-x present
            }
        }
        for(int i=0;i<=target;i++)
            cout<<dp[i]<<" ";
        return dp[target];
    }
};
