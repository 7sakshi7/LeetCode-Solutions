class Solution {
public:
    bool power3(long long x,int n){
        if(x == n)return true;
        
        if(x>n)return false;
        
        return power3(x*3,n);
    }
    bool isPowerOfThree(int n) {
        
        if(n==1)return true;
        if(n==0 || n>=INT_MAX || n<=INT_MIN || n<0)return false;
        
        
        return power3(3,n);
    }
};
