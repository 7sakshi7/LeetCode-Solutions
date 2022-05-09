class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum= 0 ;
        int j = 0;
        int maxLen = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            
            while(sum>=target){
                    sum-=nums[j];
                    j++;
                maxLen = min(maxLen,i-j+2);
            }
            
            
        }
        return maxLen == INT_MAX ? 0 : maxLen;
    }
};
