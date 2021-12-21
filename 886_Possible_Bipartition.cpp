// 96%faster
class Solution {
public:
    
    bool doColor(int i,vector<int>&colors,vector<int>adj[],int currColor){
        if(colors[i]!=-1){
            if(colors[i]!=currColor){
                return false;
            }
            return true;
        }
        colors[i] = currColor;
        
        for(auto it : adj[i]){
            if(!doColor(it,colors,adj,currColor xor 1))return false;
        }
        return true;
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>colors(n+1,-1);
        
        for(int i=1;i<=n;i++){
            if(colors[i] == -1){
                if(!doColor(i,colors,adj,0))return false;
            }
        }
        
        return true;
  
    }
};
