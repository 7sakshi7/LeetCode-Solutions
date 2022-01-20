class Solution {
public:
    bool canSolution(vector<int>piles,int h,int mid){
        int k = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]% mid !=0){
                k++;
            }
            k+=(piles[i]/mid);
            
            if(k>h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++)
            maxi = max(maxi,piles[i]);
        
        int beg = 1,end = maxi;
        int ans = -1;
        while(beg<=end){
            int mid = beg+(end-beg)/2;
            
            if(canSolution(piles,h,mid)){
                ans = mid;
                end = mid-1;
            }
            else
                beg = mid+1;
        }
        return ans;
    }
};
