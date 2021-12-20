class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>ans;        
        int diff = arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;i++){
            diff = min(arr[i+1]-arr[i],diff);
        }
        
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i] == diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        
        return ans;
    }
};
