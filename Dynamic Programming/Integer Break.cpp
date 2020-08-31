class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=i-1;
            for(int j=i-1;j>=0;j--){
                dp[i]=max(dp[i],max(dp[j],j)*max(dp[i-j],i-j));
            }
        }
        return dp[n];
    }
};
