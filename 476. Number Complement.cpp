class Solution {
public:
    int findComplement(int num) {
        uint32_t x = 1;
        int n = num;
        while(n>0){
            n = n>>1;
            x = x<<1;
            x = x | 1;
        }
        x = x>>1;
        num = num xor x;
        return num;
    }
};

// 100% faster
