//98 % faster
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        
        for(int i=1;i<intervals.size();i++){
            if(temp.back()>=intervals[i][0]){
                
                if(temp.back()<intervals[i][1]){
                    temp.pop_back();
                    temp.push_back(intervals[i][1]);
                }
                
            }
            else{
                ans.push_back(temp);
                temp.clear();
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
            }
        }
        
        if(ans.empty() || ans.back()!=temp)
            ans.push_back(temp);
        
        return ans;
    }
};
