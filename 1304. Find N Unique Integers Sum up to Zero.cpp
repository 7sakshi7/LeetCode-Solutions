class Solution {
public:
    vector<int> sumZero(int n) {
        int num = n%2 == 0 ? n : n-1;
        vector<int>res(n,0);
        int x = n;
        int i = 0,j = num-1;
        while(i<j){
            res[i] = -x;
            res[j] = x;
            i++;
            j--;
            x--;
        }
        return res;
    }
};
