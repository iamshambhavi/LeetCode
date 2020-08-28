class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0)
            return 0;
        int dp[n];
        dp[0]=1;
        int currindx2=0,currindx3=0,currindx5=0;
        for(int i=1;i<n;i++){
            int next2=dp[currindx2]*2;
            int next3=dp[currindx3]*3;
            int next5=dp[currindx5]*5;
            int nextnum=min({next2,next3,next5});
            if(nextnum==next2)
                currindx2++;
            if(nextnum==next3)
                currindx3++;
            if(nextnum==next5)
                currindx5++;
            dp[i]=nextnum;
        }
        return dp[n-1];
    }
};
