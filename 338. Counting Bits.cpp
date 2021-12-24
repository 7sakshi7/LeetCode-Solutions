// 100% faster
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        v[0] = 0;
        
        for(int i=1;i<=n;i++){
            int x = i;
            
            while(x>0){
                if(v[x]){
                    v[i]+=v[x];
                    break;
                }
                    
                if(x&1){
                    v[i]++;
                }
                x = x>>1;
            }
        }
        return v;
    }
};
