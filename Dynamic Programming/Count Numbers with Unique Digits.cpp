class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int curr=10;
        int val=9;
        for(int i=2;i<=n;i++){
            val=val*(9-i+2);
            curr=curr+val;
        }
        return curr;
    }
};
