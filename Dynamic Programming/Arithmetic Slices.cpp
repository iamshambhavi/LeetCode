class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        int curr=1,sum=0;
        for(int i=1;i<n-1;i++){
            if(A[i]-A[i-1]==A[i+1]-A[i])
                sum+=(curr++);
            else
                curr=1;
        }
        return sum;
    }
};
