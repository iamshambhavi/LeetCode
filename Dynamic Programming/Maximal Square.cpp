class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
        if(matrix.size()==0)
            return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int ans=0;
        for(int i=0;i<cols;i++){
            if(matrix[0][i]=='1'){
                dp[0][i]=1;
                ans=max(ans,dp[0][i]);
            }
        }
        for(int i=0;i<rows;i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                ans=max(ans,dp[i][0]);
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]=='1')
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
