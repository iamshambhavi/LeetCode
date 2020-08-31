class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        cout<<dp[0]<<" ";
        dp[0]=0;
        int j=0;
        int indx=0;
        for(int i=1;i<=num;i++){
            if((1<<j)==i){
                dp[i]=1;
                indx=1;
                j++;
            }
            else{
                dp[i]=dp[indx++]+1;
            }
        }
        return dp;
    }
};
