// 100% faster

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int startValue = 0,minValue=1;
        for(int i=0;i<nums.size();i++){
            startValue+=nums[i];
            
            minValue = min(minValue,startValue);
        }
        return minValue<1 ? abs(minValue)+1 : 1;
    }
};
