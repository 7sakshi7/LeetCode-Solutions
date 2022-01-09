class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            
            if(m[nums[i]] > n/3 && (v.empty() || (!v.empty() && v.back()!=nums[i]))){
                v.push_back(nums[i]);
                m[nums[i]] = 0;
            }
                
        }
        return v;
        
        
    }
};
