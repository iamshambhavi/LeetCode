class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        int dp[n][m];
        dp[0][0]=v[0][0];
        for(int i=1;i<n;i++)
            dp[i][0]=dp[i-1][0]+v[i][0];
        for(int j=1;j<m;j++)
            dp[0][j]=dp[0][j-1]+v[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++)
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+v[i][j];
        }
        return dp[n-1][m-1];
    }
};
