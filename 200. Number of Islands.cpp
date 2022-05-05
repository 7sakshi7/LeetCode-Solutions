class Solution {
public:
    int xcor[4]={0,0,1,-1};
    int ycor[4] = {1,-1,0,0};
    void dfs(int i,int j,int m,int n,vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        for(int k = 0;k<4;k++){
            dfs(i+xcor[k],j+ycor[k],m,n,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};
