class Solution {
public:
    set<vector<int>>s;
     vector<pair<int,int>> pairWithGivenSum(int i,int sum,int n,vector<int>&nums){
        int j = i,k = n-1;
        vector<pair<int,int>>v;
        while(j<k){
            int x = nums[j]+nums[k];
            if(x == sum){
                v.push_back({nums[j],nums[k]});
                while(j<k && nums[j]==nums[j+1])j++;
                while(j<k && nums[k]==nums[k-1])k--;
                j++;
                k--;
            }
            
            else if(x<sum)
            j++;
            else
            k--;
        }
        return v;
    }
    vector<vector<int>> threeSum(vector<int>& nums,int k,int sum,int t,vector<vector<int>>&res) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = k;i<n;i++){
            vector<pair<int,int>>p = pairWithGivenSum(i+1,(sum-nums[i]),n,nums);
            
            for(auto it : p){
                vector<int>temp = {t,nums[i],it.first,it.second};
                if(s.find(temp)!=s.end())
                    continue;
                else{
                    s.insert(temp);
                    res.push_back(temp);
                }
                
            }           
        }
        return res;
    } 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>res;
        if(n<4)
            return res;
        
        for(int i=0;i<=n-4;i++){
            threeSum(nums,i+1,target-nums[i],nums[i],res);
        }
        return res;
        
    }
};
