class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][i]=0;
        for(int i=0;i<n;i++){
            dp[i][i+1]=i;
        }
        for(int window=3;window<=n;window++){
            for(int i=0;i<=n-window+1;i++){
                int ans=INT_MAX;
                for(int j=i+1;j<i+window-1;j++){
                    ans=min(ans,j+max(dp[i][j-1],dp[j+1][i+window-1]));
                }
                dp[i][i+window-1]=ans;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[1][n];
    }
};
