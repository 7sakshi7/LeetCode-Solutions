class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int>row;
        
        if(numRows == 0){
            row.push_back(1);
            return row;
        }
            
         vector<vector<int>>pascals(numRows+1);
        pascals[0].push_back(1);
        
        for(int i=1;i<=numRows;i++){
            if(i == numRows){
                row.push_back(pascals[i-1][0]);
                 for(int j=1;j<pascals[i-1].size();j++){
                    row.push_back(pascals[i-1][j-1]+pascals[i-1][j]);
                }
                row.push_back(pascals[i-1][pascals[i-1].size()-1]);
            }
           else{
                pascals[i].push_back(pascals[i-1][0]);
                for(int j=1;j<pascals[i-1].size();j++){
                    pascals[i].push_back(pascals[i-1][j-1]+pascals[i-1][j]);
                }
                pascals[i].push_back(pascals[i-1][pascals[i-1].size()-1]);
               
           }
        }
        
        return row;
        
    }
};
