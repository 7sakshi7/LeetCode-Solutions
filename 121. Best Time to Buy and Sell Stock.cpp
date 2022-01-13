class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        int ans = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++){
            minPrice = min(minPrice,price[i]);
            ans = max(ans,price[i]-minPrice);
        }
        return ans;
    }
};
