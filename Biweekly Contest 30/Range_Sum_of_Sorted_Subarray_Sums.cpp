class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        int sum=0;
        int m=100000009;
        for(int i=left-1;i<right;i++){
            sum=(sum+v[i])%m;
        }
        return sum;
    }
};
