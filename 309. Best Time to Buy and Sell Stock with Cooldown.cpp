class Solution {
public:
    int dp[3][5001];
    int profit(vector<int>&prices,int action,int i){
        if(i>=prices.size())
            return 0;
        
        if(dp[action][i]!=-1)
            return dp[action][i];
        
        if(action == 0){
		//when we can buy stock we have 2 choices either buy it or don't buy
            return dp[action][i] = max(profit(prices,0,i+1),profit(prices,1,i+1)-prices[i]);
        }
        else if(action == 1){
		//when we can sell stock we have 2 choices either sell it or don't sell
            return dp[action][i] = max(profit(prices,1,i+1),profit(prices,2,i+1)+prices[i]);
        }
        else
            return dp[action][i] = max(profit(prices,2,i+1),profit(prices,0,i+1));
			// same when its cool down period 2 hoices-- either remain in cool down or buy next stock
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return profit(prices,0,0);
    }
};
