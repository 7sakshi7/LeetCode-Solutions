class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangle) {
        int n = rectangle.size();
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[min(rectangle[i][0],rectangle[i][1])]++;
        }
        
        int maxRectSize = 1;
        for(auto it : m){
            maxRectSize = max(maxRectSize,it.first);
        }
        return m[maxRectSize];
    }
};
