// 100% faster
class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==1)return true;
        
        if(n==0 || n>=INT_MAX || n<=INT_MIN)return false;
        while(n!=1){
            int x = int(n%4);
            
            if(x==0){
                n = int(n/4);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
