class Solution {
public:
    int dp[71][101][71];
    int cor[3] = {1,-1,0};
    int robo(int row,int col1,int col2,vector<vector<int>>& grid){       
       if(row == grid.size())
           return 0;
        
        if(col1<0 || col1>=grid[0].size() || col2<0 || col2>=grid[0].size())
            return INT_MIN;
        
        if(dp[col1][col2][row]!=-1)
            return dp[col1][col2][row];
        
        int ans = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                ans = max(ans,robo(row+1,col1+cor[i],col2+cor[j],grid));
            }
        }
        
        if(col1 == col2)
            ans+=grid[row][col1];
        else
            ans+=grid[row][col1]+grid[row][col2];
        
        return dp[col1][col2][row] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return robo(0,0,grid[0].size()-1,grid);
    } 
};
