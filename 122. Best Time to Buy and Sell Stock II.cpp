class Solution {
public:
    int dp[2][30002];
    int findMaxProfit(int i,int buy,vector<int>&prices){
        if(i>=prices.size())
            return dp[buy][i] = 0;
        
        if(dp[buy][i]!=-1)
            return dp[buy][i];
        
            
        if(buy){
            return dp[buy][i] = max(findMaxProfit(i+1,0,prices)-prices[i],findMaxProfit(i+1,1,prices));
        }
        else{
            return dp[buy][i] = max(findMaxProfit(i+1,0,prices),findMaxProfit(i+1,1,prices)+prices[i]);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return findMaxProfit(0,1,prices);
    }
};
