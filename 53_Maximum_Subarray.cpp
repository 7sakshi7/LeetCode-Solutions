class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSumSoFar = nums[0];
        int maxSum = nums[0];
        for(int i=1;i<nums.size();i++){
            maxSumSoFar=max(maxSumSoFar+nums[i],nums[i]);

            maxSum = max(maxSum,maxSumSoFar);
        }
        return maxSum;
    }
};
