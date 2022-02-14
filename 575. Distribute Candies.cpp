class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        
        unordered_set<int> differentTypes;
        differentTypes.insert(candyType[0]);
        for(int i = 1;i<n;i++){
           differentTypes.insert(candyType[i]);
        }
        
        int sheCanEat = n/2;
        if(sheCanEat>differentTypes.size())
            return differentTypes.size();
        return sheCanEat;
    }
};
