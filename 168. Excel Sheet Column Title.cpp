class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        while(columnNumber>0){
            if(columnNumber>=1 && columnNumber<=26){
                str.push_back((columnNumber-1)+'A');
                columnNumber = 0;
            }
            else{
                if(columnNumber%26 == 0){
                    str.push_back('Z');
                    columnNumber/=27;
                }
                else{
                    str.push_back(((columnNumber%26)-1)+'A');
                    columnNumber/=26;
                }
               
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
