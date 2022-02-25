class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>v;
        int i = 0,j=0;
        bool isUp = false,isDown = true;
        int m = mat.size(),n = mat[0].size();
        if(m==1){
            for(int i =0;i<n;i++)
                v.push_back(mat[0][i]);
            return v;
        }
        if(n==1){
           for(int i  =0;i<m;i++){
               v.push_back(mat[i][0]);
           } 
            return v;
        }
        int count = 1;
        v.push_back(mat[i][j]);
        j++;
        while(count<(m*n)){
            if(j==n){
                j--;
                i++;
                isDown = false;
                isUp = true;
                continue;
            }
            if(isDown){
                while(i<m && j>=0){
                    v.push_back(mat[i][j]);
                    i++;
                    j--;
                    count++;
                }
                i--;
                j++;
                if(i == m-1 && (j>=0 || n==2 || m==2)){
                    j++;
                }
                else{
                    i++;
                } 
                isDown = false;
                isUp = true;
            }
            else{
                while(i>=0 && j<n){
                    v.push_back(mat[i][j]);
                    i--;
                    j++;
                    count++;
                }
                j--;
                i++;
                if(j==n-1)
                    i++;
                else
                    j++;
                isDown = true;
                isUp = false;
                
            }
            
        }
        return v;
    }
};
