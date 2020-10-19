class Solution {
	bool dp[(1<<21)];
	bool canIWin(int maxChoosableInteger,int desiredTotal,int mask){
		if(desiredTotal<=0)
			return false;
		if(dp[mask])
			return true;
		for(int i=1;i<=maxChoosableInteger;i++){
			int val=1<<i;
			if(mask&val)    // It means it is visited
				continue;
			if(canIWin(maxChoosableInteger,desiredTotal-i,mask|val) == false){
                dp[mask]=true;
                return true;
            }
		}
		dp[mask]=false;
        return false;
	}
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
	   int totalSum=maxChoosableInteger*(maxChoosableInteger+1)/2;
		if(maxChoosableInteger>=desiredTotal)         
			return true;        
		if(totalSum<desiredTotal)
			return false;
		return canIWin(maxChoosableInteger,desiredTotal,0);
	}
};
