// 100% faster
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m,occ;
        
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto it : m){
            occ[it.second]++;
        }
        for(auto it : occ){
            if(it.second>1)return false;
        }
        return true;
            
    }
};
