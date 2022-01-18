class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        if(flowerbed.size()==1){
            return flowerbed[0] == 0 ? true:false;
        }
        int k = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i] == 0){
                if(i == 0 && i+1<flowerbed.size() && flowerbed[i+1]==0){
                     k++;
                    flowerbed[i] = 1;
                }                  
                else if(i == flowerbed.size()-1 && i-1>=0 && flowerbed[i-1]==0){
                     k++;
                    flowerbed[i] = 1;
                }
                else if(i>0 && i<flowerbed.size() && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                     k++;
                    flowerbed[i] = 1;
                }
               
                if(k == n)
                    return true;
            }
        }
        return false;
    }
};
