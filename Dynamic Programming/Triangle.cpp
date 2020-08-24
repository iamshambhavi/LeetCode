class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        vector<int>v;
        for(int i=0;i<triangle.size();i++){
            int a=triangle[triangle.size()-1][i];
            v.push_back(a);
        }
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                v[j]=triangle[i][j]+min(v[j],v[j+1]);
            }
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        return v[0];
    }
};
