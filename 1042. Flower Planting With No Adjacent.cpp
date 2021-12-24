class Solution {
public:
    bool canBeAssigned(int currColor,vector<int>&ans,vector<int>adj[],int src){
        
        for(auto it : adj[src]){
            if(it<ans.size() && ans[it] == currColor)
                return false;
        }
        return true;
    }
    
    void colorFlowers(int src,vector<int>&ans,vector<int>adj[],int n,int start){
        if(src == n)return;
        
        bool f = 0;
        for(int i=start;i<=4;i++){
            if(canBeAssigned(i,ans,adj,src)){
                ans.push_back(i);
                f = 1;
                cout<<ans.back()<<" ";
                break;
            }
        }
        
        if(f){
            colorFlowers(src+1,ans,adj,n,1);
        }
        else{
            int x = ans.back();
            ans.pop_back();
            colorFlowers(src-1,ans,adj,n,x+1);
        }
    }
    
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n];
        
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        
        vector<int>ans;
        ans.push_back(1);
        cout<<ans.back()<<" ";
        colorFlowers(1,ans,adj,n,1);
        
        return ans;
    }
};
