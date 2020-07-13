class Solution {
public:
    int numSub(string s) {
        long long count=0,sum=0;
        int m=1000000007;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
                sum+=count;
            }
            else{
                count=0;
            }
        }
        return sum%m;
    }
};
