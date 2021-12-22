// 100%faster
class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)return 1;
        int c = 0;
        for(int i=30;i>=0;i--){
            int x = 1<<i;
            if(!(x&n)){
                if(c!=0){
                   n = n|x; 
                }
            }
            else{
                c = 1;
                n = n&(~x);
            }
        }
        return abs(n);
    }
};
