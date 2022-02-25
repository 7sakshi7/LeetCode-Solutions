class Solution {
public:
    string decodeCiphertext(string encodedText, int row) {
        string str = "";
        if(encodedText=="")
            return str;
        if(row == 1)
            return encodedText;
        int col = encodedText.size()/row;
        
        vector<char>mat[row];
       
        for(int k = 0;k<encodedText.size();k++){
            int x = floor(k/col);
            mat[x].push_back(encodedText[k]);
        }
        
        string res = "";
        for(int i = 0;i<= mat[0].size();i++){
            int j = 0,k = i;
            while(j<row && k<col){
                res.push_back(mat[j][k]);
                j++;
                k++;
            }
        }
        int j = res.size()-1;
        while(res[j] == ' ')
            j--;
        res = res.substr(0,j+1);
        return res;
    }
};
