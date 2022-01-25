class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        res.push_back(nums[0]);
        for(int i = 1;i<n;i++){
            if(res.back()<nums[i])
                res.push_back(nums[i]);
            else{
                auto it = lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[it] = nums[i];
            }
        }
        return res.size();
        
    }
}; 
