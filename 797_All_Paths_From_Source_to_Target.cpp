// 96% faster
class Solution {
public:
    
    void dfs(int dst,int src,vector<int>&v,vector<vector<int>>&res,vector<vector<int>>& graph){
        if(src==dst){
            res.push_back(v);
            return;
        }
        for(auto it : graph[src]){
            v.push_back(it);
            dfs(dst,it,v,res,graph);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>v;
        vector<vector<int>>res;
        v.push_back(0);
        dfs(n-1,0,v,res,graph);
        
        return res;
    }
};
