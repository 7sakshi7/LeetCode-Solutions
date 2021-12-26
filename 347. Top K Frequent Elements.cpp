class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        vector<int>v;
        priority_queue<pair<int,int>>pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty() && k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};

// 92% faster
