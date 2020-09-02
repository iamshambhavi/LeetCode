class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0)
            return v;
        if(n==1){
            v.push_back(nums[0]);
            return v;
        }
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int indx=0;
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        int prev=-1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==maxi&&(prev%nums[i]==0||prev==-1)){
                prev=nums[i];
                maxi=maxi-1;
                v.push_back(nums[i]);
            }
                
        }
        return v;
    }
};
