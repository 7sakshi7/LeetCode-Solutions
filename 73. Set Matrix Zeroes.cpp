class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>storeZeroIndex;
        int m = matrix.size(),n=matrix[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    storeZeroIndex.push_back({i,j});
                }
            }
        }
        
        for(int i = 0;i<storeZeroIndex.size();i++){
            int row = storeZeroIndex[i].first,col = storeZeroIndex[i].second;
            
            int j = 0;
            while(j<m){
                matrix[j][col] = 0;
                j++;
            }
            j=0;
            while(j<n){
                matrix[row][j] = 0;
                j++;
            }
        }
    }
};
