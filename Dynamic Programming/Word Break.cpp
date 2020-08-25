class Solution {
public:
    bool wordBreak(string s, vector<string>&v) {
        int n=s.length();
        s="&"+s;
        unordered_set<string>st;
        for(auto x:v){
            st.insert(x);
        }
        bool dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        string t1="";
        t1+=s[1];
        if(st.count(t1))
            dp[1]=true;
        for(int i=2;i<=n;i++){
            for(int j=i;j>0;j--){
                string t=s.substr(j,i-j+1);
                if(st.count(t)&&dp[j-1])
                    dp[i]=true;
            }
        }
        for(int i=0;i<=n;i++)
            cout<<dp[i]<<" ";
        return dp[n];
    }
};
