class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=2*dp[i-1];
            for(int j=1;j<i-1;j++){
                dp[i]+=(dp[i-j-1]*dp[j]);
            }
        }
        return dp[n];
    }
};
