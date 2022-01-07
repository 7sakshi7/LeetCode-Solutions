class Solution {
public:
    // int fib(int i,vector<int>&arr,bool incl,int sum 9998)
    int lenLongestFibSubseq(vector<int>& arr) {
       
        unordered_map<int,int>m;
        int n = arr.size();
        
        int res = 0,count = 0;
        for(int i=0;i<n;i++)
            m[arr[i]] = i;
        
        for(int i=0;i<n-1;i++){
            int lastEle = arr[i];
            for(int j = i+1;j<n;j++){
                lastEle = arr[i];
                int curr = arr[j];
                count = 0;
                int sum = lastEle+curr;
                while(m.find(sum)!=m.end()){
                        
                        if(count == 0)
                            count+=2;
                        count++; 
                       
                        lastEle = curr;
                         curr = sum;
                    sum = curr+lastEle;
                }
                res = max(res,count);
            }
        }
        
        return res;
    }
};
