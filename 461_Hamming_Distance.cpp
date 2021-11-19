// 100% faster
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        
        for(int i=0;i<32;i++){
            int bit = (1<<i);
            if( (x&bit) xor (y&bit))
                count++;
         }
        return count;
    }
};
