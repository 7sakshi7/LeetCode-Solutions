// Approach 1 : Without using any space
class Solution {
public:
    string removeDuplicates(string s) {
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i] == s[i-1]){
                s.erase(i-1,2);
                i = i-2;
            }
        }
        return s;
    }
};

// Approach 1 : With using any space
class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(!temp.empty() && temp.back() == s[i]){
                temp.pop_back();
            }
                
            else
                temp.push_back(s[i]);
        }
        return temp;

    }
};
