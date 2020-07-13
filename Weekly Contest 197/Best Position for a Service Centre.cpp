class Solution {
    double DistanceFromAllPoints(vector<vector<int>>& positions,vector<double>& mean){
        double sum=0;
        for(auto x:positions){
            sum=sum+sqrt(pow(x[0]-mean[0],2)+pow(x[1]-mean[1],2));
        }
        return sum;
    }
    double DistanceFromAllPoints(vector<vector<int>>& positions,vector<int>& mean){
        double sum=0;
        for(auto x:positions){
            sum=sum+sqrt(pow(x[0]-mean[0],2)+pow(x[1]-mean[1],2));
        }
        return sum;
    }
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        if(positions.size()<=1)
            return 0;
        double ans=DBL_MAX;
        int n=positions.size();
        vector<double> centeroid(2,0);
        for(auto x:positions){
            centeroid[0]+=x[0];
            centeroid[1]+=x[1];
        }
        centeroid[0]=centeroid[0]/n;
        centeroid[1]=centeroid[1]/n;
        ans=min(ans,DistanceFromAllPoints(positions,centeroid));
        for(auto x:positions){
            double check=DistanceFromAllPoints(positions,x);
            if(check<ans){
                ans=check;
                centeroid[0]=x[0];
                centeroid[1]=x[1];
            }
        }
        double lower_limit=1e-5;
        double test_distance=100;
        double x[4]={1.0, 0.0, -1.0, 0.0};
        double y[4]={0.0, -1.0, 0.0, 1.0};
        while(test_distance>lower_limit){
            bool found=false;
            for(int i=0;i<4;i++){
                vector<double> checkPoint(2,0);
                checkPoint[0]=centeroid[0]+test_distance*x[i];
                checkPoint[1]=centeroid[1]+test_distance*y[i];
                double check=DistanceFromAllPoints(positions,checkPoint);
                if(check<ans){
                    ans=check;
                    centeroid[0]=checkPoint[0];
                    centeroid[1]=checkPoint[1];
                    found=true;
                    break;
                }
            }
            if(!found){
                test_distance/=2;
            }
        }
        return ans;
    }
};
