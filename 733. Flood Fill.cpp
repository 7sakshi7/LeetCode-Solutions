class Solution {
public:
    int xcor[4] = {1,-1,0,0};
    int ycor[4] = {0,0,1,-1};
    void fillColor(int i,int j,int prevColor,int newColor,vector<vector<int>>&image){
        if(i<0 || j<0 || i>=image.size()||j>=image[0].size() || image[i][j] == newColor || image[i][j]!=prevColor)
            return;
        
        image[i][j] = newColor;
        
        for(int k = 0;k<4;k++){
            fillColor(i+xcor[k],j+ycor[k],prevColor,newColor,image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        fillColor(sr,sc,prevColor,newColor,image);
        return image;
    }
};
