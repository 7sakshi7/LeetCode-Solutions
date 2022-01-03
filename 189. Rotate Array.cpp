class Solution {
public:
    void reverse(vector<int>&nums,int l,int h){
        while(l<h){
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        if(k>nums.size())k = (k-nums.size())%nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
        
    }
};
