class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = INT_MAX;
        int index = -1;
        for(int i=0;i<points.size();i++){
            if(points[i][0] == x || points[i][1] == y){
                int dis = abs(points[i][0] - x)+abs(points[i][1]-y);
                
               if(ans>dis){
                   index = i;
                   ans = dis;
               }
            }
        }
        
        return ans == INT_MAX ? -1 : index;
    }
};

// 97% faster

