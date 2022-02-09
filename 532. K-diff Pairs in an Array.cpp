class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int>m;
        int count = 0;
        bool flag = 1;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                if(k == 0 && flag){
                    count++;
                    flag = 0;
                }
                continue;
            } 
            flag = 1;
            if(m.find(nums[i])!=m.end()){
                count++;
            }
           m[nums[i]+k]++;
            
        }
        return count;
    }
};
