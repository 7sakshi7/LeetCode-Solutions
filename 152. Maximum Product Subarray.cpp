class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
       int maxProdLeft = 1,maxProdSoFar = nums[0],maxProdRight = 1;
        for(int i=0;i<n;i++){
            maxProdLeft*=nums[i];
            maxProdRight*=nums[n-i-1];
            
            maxProdSoFar = max(maxProdSoFar,max(maxProdLeft,maxProdRight));
           
            if(maxProdLeft == 0)
                maxProdLeft = 1;
            if(maxProdRight == 0)
                maxProdRight = 1;
        }
        
        return maxProdSoFar;
       
    }
};
