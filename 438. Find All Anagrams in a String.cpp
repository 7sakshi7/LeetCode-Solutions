class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(),n=p.size();
        unordered_map<char,int>pHash,sHash;
        vector<int>v;
      
        for(auto it : p){
            pHash[it]++;
        }
        
        for(int i = 0;i<p.size();i++){
            sHash[s[i]]++;
        }
        
        if(pHash.size() == sHash.size()){
            bool f = 0;
            for(auto it : pHash){
                if(sHash.find(it.first) == sHash.end() || (it.second!= sHash[it.first])){
                    f = 1;
                    break;
                }   
            }
            
             if(!f){
                v.push_back(0);
            } 
        }
     
        int j = 0;
        for(int i = p.size();i<s.size();i++){
            sHash[s[j]]--;
            if(sHash[s[j]] == 0){
                sHash.erase(s[j]);
            }
            j++;
            sHash[s[i]]++;
             bool f = 0;
            for(auto it : pHash){
                if(sHash.find(it.first) == sHash.end() || (it.second!= sHash[it.first])){
                    f = 1;
                    break;
                }   
            }
            
             if(!f){
                v.push_back(j);
            }  
            
        }
        return v;
            
    }
};
