class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCase = 0,lowerCase = 0;
        bool middle = false;
        if(isupper(word[0]))
            upperCase++;
        else
            lowerCase++;
        
        for(int i=1;i<word.size();i++){
            if(isupper(word[i])){
                upperCase++;
                middle = true;
            }
                
            else
                lowerCase++;
        }
        
        if(upperCase == word.size() || lowerCase == word.size() || (upperCase==1 && !middle))
            return true;
        return false;
            
    }
};
