class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        
        int n = s1.size(),m = s2.size();
        
        int count[26] = {0};
        int count2[26] = {0};
        
        for(int i=0;i<n;i++){
            count2[s2[i]-'a']++;
            count[s1[i]-'a']++;
        }

        bool found = true;
        for(int i=0;i<26;i++){
            if(count[i]!=count2[i]){
                found = false;
                break;
            }
        }
        if(found)return true;
        
        int i = n,j = 0;
        while(i<m){
            count2[s2[j]-'a']--;
            j++;
            count2[s2[i]-'a']++;
            i++;
            found = true;
            for(int k=0;k<26;k++){
                if(count[k]!=count2[k]){
                      found = false;
                    break;
                }                                       
          }
            
        if(found)
            return true;                
        }
        return false;
    }
};
