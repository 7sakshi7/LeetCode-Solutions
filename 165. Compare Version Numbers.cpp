class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int i = 0,j=0;
        int m = ver1.size(),n = ver2.size();
        while(i<m || j<n){
            int sum1 = 0,sum2 = 0;
            if(i < m){
                while(i<m && ver1[i]!='.'){
                    sum1 = sum1*10+(ver1[i]-'0');
                    i++;
                }
                if(ver1[i]=='.')
                    i++;
            }
            if(j<n){
                 while(j<n && ver2[j]!='.'){
                    sum2 = sum2*10+(ver2[j]-'0');
                    j++;
                }
                if(ver2[j]=='.')
                    j++;
            }
            
            if(sum1<sum2)
                return -1;
            if(sum1>sum2)
                return 1;
                
        }
        return 0;
    }
};
