class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.empty())
            return 0;
        int dp[26];
        memset(dp,0,sizeof(dp));
        dp[p[0]-'a']=1;
        int pos=0;
        for(int i=1;i<p.size();i++){
            if((p[i]-p[i-1]+26)%26!=1)
                pos=i;
            dp[p[i]-'a']=max(dp[p[i]-'a'],i-pos+1);
        }
        int sum=0;
        for(int i=0;i<26;i++)
            sum+=dp[i];
        return sum;
    }
};
