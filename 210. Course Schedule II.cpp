// 94% faster
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        unordered_map<int,int>indeg;
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(indeg.find(i)==indeg.end())
                q.push(i);
        }
        
        vector<int>order;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            order.push_back(x);
            
            for(auto it : adj[x]){
                indeg[it]--;
                
                if(indeg[it] == 0)
                    q.push(it);
            }
        }
        
        if(order.size()<numCourses-1)
            order.clear();
        return order;
    }
};
