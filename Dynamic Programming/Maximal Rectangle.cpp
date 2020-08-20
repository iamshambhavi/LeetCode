class Solution {
public:
    int histogram(int*dp,int m){
        stack<int>s;
        int maxi=0;
        int topEl;
        int topArea;
        int i=0;
        while(i<m){
            if(s.empty()||dp[s.top()]<=dp[i])
                s.push(i++);
            else{
                topEl=s.top();
                s.pop();
                topArea=dp[topEl];
                if(s.empty())
                    topArea*=i;
                else
                    topArea*=(i-s.top()-1);
                if(maxi<topArea)
                    maxi=topArea;
            }
        }
        while(!s.empty()){
            topEl=s.top();
                s.pop();
                topArea=dp[topEl];
                if(s.empty())
                    topArea*=i;
                else
                    topArea*=(i-s.top()-1);
            
                if(maxi<topArea)
                    maxi=topArea;
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& v) {
        int n=v.size();
        if(n==0)
            return 0;
        int m=v[0].size();
        int dp[m];
        int maxArea=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='0')
                    dp[j]=0;
                else{
                    dp[j]+=1;
                }
            }
            int currMaxArea=histogram(dp,m);
            if(currMaxArea>maxArea)
                maxArea=currMaxArea;
        }
        return maxArea;
    }
};
