class Solution {
public:
    int xcor[4] = {0,0,1,-1};
    int ycor[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,int &c){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        c++;
        for(int k = 0;k<4;k++){
            dfs(grid,i+xcor[k],j+ycor[k],m,n,c);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(),n=grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    int c = 0;
                    dfs(grid,i,j,m,n,c);
                    count = max(count,c);
                }
            }
        }
        return count;
    }
};
