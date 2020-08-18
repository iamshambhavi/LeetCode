class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return "";
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int maxi=1,start=0;
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                start=i-1;
                dp[i-1][i]=true;
                maxi=2;
            }
        }
        for(int k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j=i+k;
                if(s[i]==s[j]&&dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    if(maxi<(j-i+1)){
                        maxi=j-i+1;
                        start=i;
                    }
                }
            }
        }
            return s.substr(start,maxi);
    }
 
};
