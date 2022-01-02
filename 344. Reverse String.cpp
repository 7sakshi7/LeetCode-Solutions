class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0,h = s.size()-1;
        while(l<h){
            char c = s[l];
            s[l] = s[h];
            s[h] = c;
            l++;
            h--;
        }
    }
};
