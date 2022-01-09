// 1st Approach : With Memoization
class Solution {
public:
    int dp[1001];
     int minCost(int i,vector<int>&cost){
         if(i>=cost.size())
             return 0;
        
         if(i == cost.size()-1)
             return dp[i] = cost[i];
        
         if(dp[i]!=-1)
             return dp[i];
        
         return dp[i] =  min(minCost(i+1,cost),minCost(i+2,cost)) + cost[i];
     }
    int minCostClimbingStairs(vector<int>& cost) {
         memset(dp,-1,sizeof(dp));
        return min(minCost(0,cost),minCost(1,cost));     
    }
};

// 2nd Approach : Bottom Up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {        
        int n = cost.size();
     
        if(n == 2)
            return min(cost[0],cost[1]);
        
        int dp[n+1];
        dp[n] = 0;
        dp[n-1] = cost[n-1];
       
        for(int i = n-2;i>=0;i--){
            dp[i] = min(dp[i+1],dp[i+2])+cost[i];
        }
        return min(dp[0],dp[1]);
        
    }
};
