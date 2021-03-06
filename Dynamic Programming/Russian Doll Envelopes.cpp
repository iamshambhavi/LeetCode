class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
    return a[0]*a[1] < b[0]*b[1]; 
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0)
            return 0;
        if(envelopes.size()==1)
            return 1;
        vector<int>dp(envelopes.size(),0);
        sort(envelopes.begin(),envelopes.end(),cmp);
        for(int i=0;i<envelopes.size();i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int maxi=INT_MIN;
        for(auto x:dp)
            maxi=max(maxi,x);
        return maxi;
    }
};
