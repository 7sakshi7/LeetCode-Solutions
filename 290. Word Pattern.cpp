class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,vector<int>>pt;
        unordered_map<string,vector<int>>st;
        int stl = 0;
        for(int i=0;i<pattern.size();i++){
            pt[pattern[i]].push_back(i);
            
            string str = "";
            if(stl>=s.size())return false;
            while(stl < s.size() && s[stl]!=' '){
                str.push_back(s[stl]);
                stl++;
            }
            stl++;
            
            st[str].push_back(i);
            
            
            if(pt[pattern[i]] != st[str])
                return false;
        }
        if(stl<s.size())return false;
        return true;
    }
};
