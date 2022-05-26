class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      set<int>st;
        
        for(auto it : nums){
            st.insert(it);
        }
        
        int maxCount = 0,count = 0;
        int lastEle = INT_MAX;
        for(auto it : st){
            if(lastEle == INT_MAX){
                count++;
            }
            
            else if(it-lastEle == 1)
                count++;
            else
                count = 1;
            
            lastEle = it;
            
            maxCount = max(maxCount,count);
        }
        return maxCount;
            
    }
};
