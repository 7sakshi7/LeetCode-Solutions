class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return false;
        int inc = 0,dec=0;
        for(int i = 1;i<n;i++){
            if(arr[i]>arr[i-1]){
                if(dec!=0)
                    return false;
                inc++;
            }
            else if(arr[i] == arr[i-1])
                return false;
            else{
                if(inc == 0)
                    return false;
                dec++;
            }
        }
        return dec == 0 ? false : true;
    }
};
