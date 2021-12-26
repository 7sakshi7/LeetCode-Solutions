class Solution 
{
    public:
    //Function to find minimum number of pages.
    static bool isPossible(int sum,int arr[],int n,int m){
        int student= 1,amt =0;
        bool canWe = true;
        for(int i=0;i<n;i++){
            amt+=arr[i];
            
            if(amt>sum){
                student++;
                amt = arr[i];
            }
            
            if(student>m)return false;
        }
        
        // if(student!=m)return false;
        return true;
        
        
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        int end = 0;
        int beg = 0,ans = -1;
        for(int i=0;i<N;i++){
            end+=A[i];
            beg = max(A[i],beg);
        }
        
        
        while(beg<=end){
            long long int mid = beg + (end-beg)/2;
            
            if(isPossible(mid,A,N,M)){
                ans = mid;
                end = mid-1;
            }
            
            else{
                beg = mid+1;
            }
        }
        return ans;
    }
};
