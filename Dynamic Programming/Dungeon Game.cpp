class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        if(dungeon[m-1][n-1]>0)
            dp[m-1][n-1]=1;
        else
            dp[m-1][n-1]=abs(dungeon[m-1][n-1])+1;
        for(int i=m-2;i>=0;i--){
            if(dp[i+1][n-1]-dungeon[i][n-1]>0)
                dp[i][n-1]=dp[i+1][n-1]-dungeon[i][n-1];
            else
                dp[i][n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(dp[m-1][i+1]-dungeon[m-1][i]>0)
                dp[m-1][i]=dp[m-1][i+1]-dungeon[m-1][i];
            else
                dp[m-1][i]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=max(min(dp[i][j+1]-dungeon[i][j],dp[i+1][j]-dungeon[i][j]),1);
            }
        }
        return dp[0][0];
    }
};
