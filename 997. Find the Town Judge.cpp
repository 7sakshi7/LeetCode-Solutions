class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n];
        unordered_map<int,int>indeg;
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]-1].push_back(trust[i][1]-1);
            indeg[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==0 && indeg[i] == n-1){
                return i+1;
            }
        }
        return -1;
    }
};
