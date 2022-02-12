class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        if(n == 2){
            if(nums[0]<0)
                return nums[1]<0;
            return nums[1]>0;
        }
        for(int i=0;i<n;i++){
            int j = INT_MAX;
            unordered_map<int,int>m;
            bool pos = 0,neg = 0;
            if(nums[i]<0)
                neg = 1;
            else
                pos = 1;
            while(j!=i && (m.find(j) == m.end())){
                if(j == INT_MAX)
                    j = i;
                if(nums[j]> 0 && !pos)
                    break;
                if(nums[j]<0 && !neg)
                    break;
                m[j]++;
                
               if(pos){
                   
                   j = (j+nums[j])%nums.size();
               }
                    
                else{
                    j = (j+nums[j] + nums.size())%nums.size();
                }
                    
            }
            if(j == i && m.size()>1)
                return true;
        }
        return false;
    }
};
