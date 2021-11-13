// 87% faster

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>v(n);
        v[n-1] = 0;
        stack<int>s;
        s.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && temp[s.top()]<=temp[i])
                s.pop();
            if(s.empty())
                v[i] = 0;
            else
                v[i] = s.top()-i;
            
            s.push(i);
        }
        return v;
    }
};
