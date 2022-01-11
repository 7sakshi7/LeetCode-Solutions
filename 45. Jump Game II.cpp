class Solution {
public:
    int dp[100000];
    int jump(vector<int>& nums) {
        int n = nums.size();     
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<nums.size();i++){
            for(int j = 1;j<=nums[i];j++){
                if(i+j<=n && dp[i+j]!=0)
                dp[i+j] = min(dp[i+j],dp[i]+1);
                else if(i+j<=n)
                    dp[i+j] = dp[i]+1;
            }
        }
        return dp[nums.size()-1];
    }
};      
