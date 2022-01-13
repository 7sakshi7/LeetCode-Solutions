class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        
        int count = 1;
        pair<int,int>p = {points[0][0],points[0][1]};
        
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=p.second){
                p.second = min(p.second,points[i][1]);
            }
            else{
                count++;
                p = {points[i][0],points[i][1]};
            }
        }
        return count;
    }
};
