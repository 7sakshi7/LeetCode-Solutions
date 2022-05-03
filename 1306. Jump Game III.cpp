class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size())
            return false;
        
        if(arr[start] == 0)
            return true;
        
        if(arr[start] == INT_MAX)
            return false;
        
        int x = arr[start];
        arr[start] = INT_MAX;
        
        return canReach(arr,start+x) || canReach(arr,start-x);
    }
};
