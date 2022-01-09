class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        if(n==1 || n == 2)return arr[0];
        
        if(n == 3){
            if(arr[0] == arr[1])
                return arr[0];
                return arr[2];
        }
        
        int res = 0,c=0;
        for(int i=1;i<n;i++){
            if(arr[i] == arr[res])
                c++;
            else
                c--;
            if(c<0){
                res = i;
                c = 0;
            }
        }
     return arr[res];
    }
};
