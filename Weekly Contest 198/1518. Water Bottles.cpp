class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        while(numBottles>=numExchange){
            int a=numBottles/numExchange;
            int b=numBottles%numExchange;
            numBottles=a+b;
            sum+=a;
        }
        return sum;
    }
};
