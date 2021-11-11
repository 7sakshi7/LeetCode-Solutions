class Solution {
public:
    int dp[2][30001];
    
    int calcProfit(vector<int>&prices,int hold,int i){
        if(i>=prices.size())return 0;
        
        if(dp[hold][i]!=-1)return dp[hold][i];
        
        if(hold){
            return dp[hold][i] = max(calcProfit(prices,1-hold,i+1)+prices[i],calcProfit(prices,hold,i+1));
        }
        else
            return dp[hold][i] = max(calcProfit(prices,1,i+1)-prices[i],calcProfit(prices,hold,i+1));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return calcProfit(prices,0,0);
    }
};
