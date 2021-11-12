class Solution {
public:
    bool isFeasible(int k,int pos,vector<int>&positions){
        for(int i=0;i<positions.size();i++){
            if(positions[i]==pos || (abs(i-k)==abs(positions[i]-pos)))return false;
        }
        return true;
    }
    
   void allPositions(int k,int n,vector<int>&positions,vector<vector<int>>&combination){
        if(k==n){
            combination.push_back(positions);
            return;
        }
       
        for(int i=0;i<n;i++){
            if(isFeasible(k,i,positions)){
                positions.push_back(i);
                allPositions(k+1,n,positions,combination);
                positions.pop_back();
            }               
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>combination;
        vector<int>positions;
        
        allPositions(0,n,positions,combination);
        
        vector<vector<string>>res;
        for(int i=0;i<combination.size();i++){
            vector<string>temp;
            for(int j=0;j<n;j++){
                string s;
                for(int k=0;k<combination[i][j];k++)
                    s.push_back('.');
                s.push_back('Q');
                
                for(int k=combination[i][j]+1;k<n;k++)
                    s.push_back('.');
                
                temp.push_back(s);
            }
            res.push_back(temp);
        }
        return res;
    }
};
