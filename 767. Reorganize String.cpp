class Solution {
public:
    string reorganizeString(string s) {
        string str = "";
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>m;
        
        for(auto it : s){
            m[it]++;
        }
        
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty()){
            pair<int,char>p = pq.top();
            pq.pop();
            
            if(p.second == str.back()){
               if(pq.empty())
                   return "";
                
                else{
                    str.push_back(pq.top().second);  
                    pair<int,char>t = pq.top();
                    pq.pop();
                    
                    pq.push(p);
                    if(t.first>1)
                    pq.push({t.first-1,t.second});
                }
            }
            else{
                str.push_back(p.second);  
                if(p.first>1)
                pq.push({p.first-1,p.second});
       
        }
        
        return str;
    }
};
