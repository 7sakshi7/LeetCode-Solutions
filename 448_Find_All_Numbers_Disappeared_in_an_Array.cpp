class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
            }
            else
                nums[nums[i]-1] = -abs(nums[nums[i]-1]);
        }
        
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                v.push_back(i+1);
            }
        }
        
        return v;
    }
};
