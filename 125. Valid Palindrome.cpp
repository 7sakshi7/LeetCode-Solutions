class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0,j = s.size()-1;
        while(i<j){
            if(isdigit(s[i]) && isalpha(s[j]))return false;
            else if(isdigit(s[j]) && isalpha(s[i]))return false;
            else if(isdigit(s[i]) && isdigit(s[j])){
                if(s[i]!=s[j])return false;
                i++;
                j--;
            }
            else if(isalpha(s[i])&&isalpha(s[j])){
                if(isupper(s[i]))
                    s[i] +=32;
                if(isupper(s[j]))
                    s[j]+=32;
                
                cout<<s[i]<<" "<<s[j]<<endl;
                if(s[i]!=s[j])return false;
                
                i++;
                j--;
            }
            else if(isalpha(s[i]) || isdigit(s[i]))
                j--;
            else
                i++;
        }
        return true;
    }
};
