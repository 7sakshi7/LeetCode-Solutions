class Solution {
public:
    static bool cmp(pair<int,string>&a,pair<int,string>&b){
        if(a.first<b.first)return false;
        
        else if(a.first == b.first)return a.second<b.second;
        
        return true;
    }
    vector<string> topKFrequent(vector<string>& nums, int k) {
        unordered_map<string,int>m;
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        vector<string>v;
        
       vector<pair<int,string>>res;
        
        for(auto it : m){
            res.push_back({it.second,it.first});
        }
        
        sort(res.begin(),res.end(),cmp);
        
        for(int i=0;i<k;i++)
            v.push_back(res[i].second);
        
        return v;
    }
};



