class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<float,vector<vector<int>>>distance;
        for(int i=0;i<points.size();i++){
            float dis = ((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            distance[dis].push_back(points[i]);
        }
        
        vector<vector<int>>ans;
        auto it = distance.begin();
        while(k>0){
            cout<<k<<endl;
            if(it->second.size()<=k){
                k -= it->second.size();
                
                for(auto itr : it->second)
                    ans.push_back(itr);
            }
            else{
                int x = it->second.size() - k;
                k = 0;
                auto itr = it->second.begin();
                while(x--){
                    ans.push_back(*itr);
                    itr++;
                }
            }
            it++;
        }
        return ans;
    }
};
