class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans^=s[i]+'0';
        }
        
        cout<<ans<<endl;
        
        for(int i=0;i<t.size();i++){
            cout<<(t[i]+'0')<<endl;
            ans^=t[i]+'0';
        }
        
        cout<<ans<<endl;
        
        char c = (ans - 'a');
        char d = 'a'+ (c - '0');
        return d;
        
        
    }
};


// @nd Approach 75% faster
class Solution {
public:
    char findTheDifference(string s, string t) {
       
        unordered_map<char,int>st;
        
        for(int i=0;i<t.size();i++){
            st[t[i]]--;
            if(i<s.size())
            st[s[i]]++;
        }
        
        for(auto it : st){
            if(it.second<0)return it.first;
        }
        return 'a';
        
    }
};
