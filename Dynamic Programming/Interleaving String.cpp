class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int l=s3.length();
        if(l!=(n+m))
            return false;
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;
        int k=0;
        for(int i=1;i<=n;i++){
            if(s1[i-1]!=s3[i-1])
                dp[i][0]=false;
            else
                dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<=m;i++){
            if(s2[i-1]!=s3[i-1])
                dp[0][i]=false;
            else
                dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=false;
                if(s3[i+j-1]==s1[i-1])
                    dp[i][j]|=dp[i-1][j];
                if(s3[i+j-1]==s2[j-1])
                    dp[i][j]|=dp[i][j-1];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};
