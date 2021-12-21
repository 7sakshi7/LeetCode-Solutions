// Approach 1 : 
// 40% faster
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n==1)return true;
        int x = 1;
        for(int i=1;i<=31;i++){
            x = x<<1;
            if(x == n)return true;
            
            if(x>n)return false;
        }
        return false;
    }
};

// Approach 2 : 
// 100% faster
class Solution {
public:
    
    bool isPowerOfTwo(int n) {  
        if(n==1)return true;
        if(n==0)return false;
        
        if(n>=INT_MAX || n<= INT_MIN)return false;        
         int x = log2(abs(n));
        
        return pow(2,x) == n ?  true : false;
    }
    
};
