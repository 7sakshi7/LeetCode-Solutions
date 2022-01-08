class Solution {
public:
    string capitalizeTitle(string title) {
        string str = "";
        string res = "";
        for(int i=0;i<title.size();i++){
            if(title[i] == ' '){
                if(str.size()<=2){
                    transform(str.begin(), str.end(), str.begin(), ::tolower);
                    // str.tolower();
                    if(res!="")
                    res  = res+" "+str;
                    else
                    res = str;
                }
                else{
                    transform(str.begin(), str.end(), str.begin(), ::tolower);
                    // str.tolower();
                    str[0] = toupper(str[0]);
                    if(res!="")
                    res  = res+" "+str;
                    else
                    res = str;
                }
                
                str.clear();
            }
            else{
                str.push_back(title[i]);
            }
        }
         if(str.size()<=2){
                    transform(str.begin(), str.end(), str.begin(), ::tolower);
                    // str.tolower();
                   if(res!="")
                    res  = res+" "+str;
                    else
                    res = str;
                }
                else{
                    transform(str.begin(), str.end(), str.begin(), ::tolower);
                    // str.tolower();
                    str[0] = toupper(str[0]);
                    if(res!="")
                    res  = res+" "+str;
                    else
                    res = str;
                }
        return res;
    }
};
