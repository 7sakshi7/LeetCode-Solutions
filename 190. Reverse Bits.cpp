// 100% faster
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t maxDigit = 1<<31;
        uint32_t minDigit = 1;
        
        while(maxDigit>minDigit){
            uint32_t x = maxDigit&n;
            uint32_t y = minDigit&n;
                        
            if(x!=y && ((x>0 && y<=0) || (x<=0 && y>0))){   
                if(x){
                  n = n&(~(maxDigit));  
                }
                else{
                   n = n|maxDigit; 
                }
                if(y){
                    n = n&(~(minDigit));  
                }
                else{
                     n = n|minDigit;
                }
            }           
            maxDigit = maxDigit>>1;
            minDigit = minDigit<<1;
        }
        return n;
        
    }
};
