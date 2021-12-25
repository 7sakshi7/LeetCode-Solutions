// 100% faster
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int beg = 0,end = arr.size();
        if(end == 1)return 0;
        if(end == 2)return arr[0]>arr[1] ? 0:1 ;
        
        if(arr[0]>arr[1])return 0;
        
        if(arr[arr.size()-1]>arr[arr.size()-2])return arr.size()-1;
        
        int i = 1,j = arr.size()-2;
        while(i<arr.size()-1 && i<j&& j>0){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])return i;
            
            if(arr[j]>arr[j+1] && arr[j]>arr[j-1])return j;
            i++;j--;
        }
        
        if(i == j && arr[i]>arr[i-1] && arr[i]>arr[i+1])return i;
        return -1;
    }
};
