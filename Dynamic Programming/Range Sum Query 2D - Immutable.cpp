class NumMatrix {
public:
    vector<vector<int> > dp;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int>v;
            int ans=0;
            for(int j=0;j<matrix[i].size();j++){
                v.push_back(ans+matrix[i][j]);
                ans+=matrix[i][j];
            }
            dp.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        if(col1==0){
            for(int i=row1;i<=row2;i++){
                ans+=dp[i][col2];
            }
            return ans;
        }
        for(int i=row1;i<=row2;i++){
            int temp=dp[i][col2]-dp[i][col1-1];
            ans+=temp;
        }
        return ans;
    }
};
