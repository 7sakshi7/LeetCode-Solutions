class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        
        if(n==2)return max(nums[0],nums[1]);
        
        if(n==3)return max(nums[0],max(nums[1],nums[2]));
        
        int dp[n];
        int lastHouse[n];
        lastHouse[n-1] = 0;
        lastHouse[n-2] = nums[n-1];
        lastHouse[n-3] = nums[n-2];
        
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = nums[1];
        
        for(int i = 3;i<n;i++){
            dp[i] = max(dp[(i-1)],max(dp[(i-2)%n],dp[(i-3)%n])+nums[i-1]);
        }
        cout<<endl;
        
        for(int i = n-4;i>=0;i--){
            lastHouse[i] = max(lastHouse[i+1],max(lastHouse[(i+3)%n],lastHouse[(i+2)%n])+nums[i+1]);
        }
        
        
        return max(lastHouse[0],dp[n-1]);
    }
};
