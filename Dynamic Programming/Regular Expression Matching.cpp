class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        if(m==0&&n==0)
            return true;
        if(m==0)
            return false;
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=true;
        if(p[0]=='*')
            dp[0][1]=true;
        else
            dp[0][1]=false;
        for(int i=2;i<=m;i++){
            if(p[i-1]=='*'){
                dp[0][i]=dp[0][i-2];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];
                    if(s[i-1]==p[j-2]||p[j-2]=='.'){
                        dp[i][j]=dp[i][j]|dp[i-1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};
