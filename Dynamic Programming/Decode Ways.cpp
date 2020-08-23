class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0||s[0]=='0')
            return 0;
        int dp[n+1];
        dp[0]=1;
        if(n==1)
            return dp[0];
       dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i]=='0'){
                if((s[i-1]-'0')*10+(s[i]-'0')==10||(s[i-1]-'0')*10+(s[i]-'0')==20)
                    dp[i]=dp[i-2];
                else if((s[i-1]-'0')*10+(s[i]-'0')>10&&(s[i-1]-'0')*10+(s[i]-'0')<=26)
                    dp[i]=dp[i-1]+1;
                else
                    return 0;  
            }
            else if((s[i-1]-'0')*10+(s[i]-'0')>=10&&(s[i-1]-'0')*10+(s[i]-'0')<=26){
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
                dp[i]=dp[i-1];
        }
        return dp[n];
    }
};
