class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return false;
        int n=stones.size();
        vector<unordered_set<int>>dp(n);
        dp[1].insert(1);
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int diff=stones[i]-stones[j];
                if(diff==2147483647)
                    return false;
                if(dp[j].count(diff-1)||dp[j].count(diff)||dp[j].count(diff+1))
                    dp[i].insert(diff);
            }
        }
        if(!dp[n-1].empty())
            return true;
        return false;
    }
};
