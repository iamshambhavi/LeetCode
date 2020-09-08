class Solution {
    int numberOfSubArrays(vector<int>& nums,long long midsum){
        int subArrays=1;
        long long currSum=0;
        for(int i=0;i<nums.size();i++){
            if(currSum+nums[i]>midsum){
                subArrays++;
                currSum=nums[i];
            }
            else
                currSum+=nums[i];
        }
        return subArrays;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int lowsum=0;
        long long highsum=0;
        for(int i=0;i<n;i++){
            lowsum=max(lowsum,nums[i]);
            highsum+=nums[i];
        }
        while(lowsum<highsum){
            int midsum=(lowsum+highsum)/2;
            int subArrays=numberOfSubArrays(nums,midsum);
            if(subArrays>m)
                lowsum=midsum+1;
            else
                highsum=midsum;
        }
        return lowsum;
    }
};
