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
