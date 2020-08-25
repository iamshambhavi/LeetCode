class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()/2<1||k==0)
            return 0;
        if(k>=(prices.size()/2)){
            int sum=0;
            for(int i=0;i<prices.size()-1;i++){
                if(prices[i+1]>prices[i])
                    sum+=prices[i+1]-prices[i];
            }
            return sum;
        }
        int buy[k+1],sell[k+1];
        for(int i=0;i<=k;i++)
            buy[i]=INT_MAX;
        for(int i=0;i<=k;i++)
            sell[i]=0;

        for(int i=0;i<prices.size();i++){
            buy[0]=min(buy[0],prices[i]);
            sell[0]=max(sell[0],prices[i]-buy[0]);
            for(int j=1;j<k;j++){
                buy[j]=min(buy[j],prices[i]-sell[j-1]);
                sell[j]=max(sell[j],prices[i]-buy[j]);
            }
        }
        return sell[k-1];
    }
};
