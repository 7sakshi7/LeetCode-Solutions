class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        nums.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
               if(count<2){
                   nums.push_back(nums[i]);
               }
                count++;
            }
            else{
               count = 1;
                nums.push_back(nums[i]);
            }
        }
        int m = nums.size();
        for(int i = n;i<m;i++){
            nums[i-n] = nums[i];
        }
        return (m-n);
    }
};
