class Solution {
public:
    int numberOfSteps(int num) {
        if(num<=1)
            return num;
        int dp[num+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=num;i++){
            if(i&1){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i] = min(dp[i-1],dp[i/2])+1;
            }
        }
        return dp[num];
    }
};
