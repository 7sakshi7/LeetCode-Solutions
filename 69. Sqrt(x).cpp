class Solution {
public:
    int mySqrt(int x) {
        
        int beg = 0,end = x;
        int ans = 0;
        while(beg<=end){
            
             if(end == INT_MAX){
                end = end/2;
                
            }
            long long int mid = beg + (end-beg)/2;
            cout<<mid<<endl;
            
            long long int prod = mid*mid;
        
            if(prod == x)
                return mid;
            
            if(prod>x){
                end = mid-1;
            }
            else{    
                ans = mid;
                beg = mid+1;
            }
        } 
        if(beg == end)return beg;
        return ans;
    }
};

1000%faster
