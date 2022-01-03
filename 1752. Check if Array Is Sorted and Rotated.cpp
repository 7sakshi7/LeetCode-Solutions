class Solution {
    private:
    void reverse(vector<int>&nums,int l,int h){
        while(l<h){
            int temp = nums[l];
            nums[l] = nums[h];
            nums[h] = temp;
            l++;
            h--;
        }
    }
public:
    bool check(vector<int>& nums) {
        int minElement = INT_MAX,minElementIndex = 0;
        
        for(int i=0;i<nums.size();i++){
            if(minElement>nums[i]){
                minElement = nums[i];
                minElementIndex = i;
            }
        }
        
        if(minElementIndex == 0 && nums[0] == nums[nums.size()-1]){
            int j = nums.size()-1;
            while(j>0 && nums[j] == nums[0]){
                j--;
            }
            minElementIndex = j+1;
        }
       
            reverse(nums,0,minElementIndex-1);
            reverse(nums,minElementIndex,nums.size()-1);
            
            for(int i=1;i<nums.size();i++){
                if(nums[i]>nums[i-1])return false;
            }
        
        return true;
        
    }
    
};
