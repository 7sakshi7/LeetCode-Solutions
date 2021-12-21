class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t x = 1;
        
        for(int i = 31;i>=0;i--){
            if(x&n){
                count++;
            }
            x = x<<1;
        }
        return count;
    }
};

// 100%faster
class Solution {
public:
    int hammingWeight(uint32_t n) {
       return n==0 ? 0 : 1+hammingWeight(n&(n-1));
    }
};
