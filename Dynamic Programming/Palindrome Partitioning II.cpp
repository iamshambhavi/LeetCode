class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])
                dp[i-1][i]=true;
        }
        for(int k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j=i+k;
                if(s[i]==s[j]&&dp[i+1][j-1]==true)
                    dp[i][j]=true;
            }
        }
        int numCuts[n];
        memset(numCuts,0,sizeof(numCuts));
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            if(dp[0][i])
                numCuts[i]=0;
            else{
                for(int j=0;j<i;j++){
                    if((dp[j+1][i])&&mini>numCuts[j]+1)
                        mini=numCuts[j]+1;
                }
                numCuts[i]=mini;
            }
        }
        return numCuts[n-1];
    }
};
