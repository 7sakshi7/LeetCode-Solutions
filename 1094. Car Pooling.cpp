class Solution {
    private:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        unordered_set<int>s;
        int passengers = trips[0][0];
        if(passengers>capacity)return false;
        int j = 0;
        for(int i=1;i<trips.size();i++){
            if(trips[i][0]+passengers > capacity){
                for(int j=0;j<i;j++){
                    if(trips[j][2]<=trips[i][1] && s.find(j) == s.end()){
                        passengers-=trips[j][0];
                        s.insert(j);
                    }
                }
                cout<<passengers<<endl;
                if(trips[i][0]+passengers > capacity)return false;
                else
                   passengers+=trips[i][0]; 
            }
            
            else{
                passengers+=trips[i][0];
            }
        }
        return true;
    }
};
