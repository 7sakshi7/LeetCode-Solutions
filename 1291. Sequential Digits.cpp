class Solution {
public:
    void dfs(int i,int curr,int low,int high,vector<int>&seq){
        if(curr>high)
            return;
        if(curr>=low || curr == high){
            seq.push_back(curr);
        }
        curr = curr*10;
        for(int j = i;j<=9;j++){
            curr+=j;
            return dfs(j+1,curr,low,high,seq);
            curr-=j;
            
        }
        
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>seq;
        for(int i = 1;i<=9;i++){
            dfs(i,0,low,high,seq);
        }
        sort(seq.begin(),seq.end());
        return seq;   
    }
};
