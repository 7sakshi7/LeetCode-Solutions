class Solution {
public:
    int dp[101][101];
    int uniquePath(int i,int j,int m,int n,vector<vector<int>>&grid){
        if(i == m-1 && j == n-1){
            if(grid[i][j]==1)
                return dp[i][j]= 0;
            return dp[i][j] = 1;
        }
        
        if(i>=m || j>=n){
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(grid[i][j] == 1)
            return dp[i][j] = 0;
        return dp[i][j]= uniquePath(i+1,j,m,n,grid)+uniquePath(i,j+1,m,n,grid);
            
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        return uniquePath(0,0,m,n,grid);
    }
};
