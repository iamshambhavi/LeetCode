class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        if(v[0][0]==1)
            return 0;
        dp[0][0]=1;
        int val=1;
        for(int i=1;i<n;i++){
            if(v[i][0]==1)
                 val=0;
            dp[i][0]=val;
        }
        val=1;
        for(int j=1;j<m;j++){
            if(v[0][j]==1)
                val=0;
            dp[0][j]=val;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][j]==1)
                    continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
