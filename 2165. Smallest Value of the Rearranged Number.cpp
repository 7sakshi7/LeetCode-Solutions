class Solution {
public:
    long long smallestNumber(long long num) {
        if(num>=0 && num<=9)
            return num;
        int zeroPlace = 1;
        string str ;
        bool neg  = 0;
        if(num<0){
            neg = 1;  
            num= -num;
             str= to_string(num);
            zeroPlace = str.size()-1;
            for(int i = 1;i<str.size();i++){
                int j = i-1;
                char temp = str[i];
                while(j>=0){
                        if((str[j]-'0')<(temp-'0')){
                        str[j+1] = str[j];
                    }
                    else
                        break;
                    j--;
                }
                str[j+1] = temp;
            }
        }
        else{
            str= to_string(num);
            for(int i = 1;i<str.size();i++){
                int j = i-1;
                int temp = str[i] - '0';
                while(j>=0){
                    if((str[j]-'0')>temp ){
                        str[j+1] = str[j];
                    }
                    else
                        break;
                    j--;
                }
                str[j+1] = temp+'0';
            }
        }
        long long sum = 0;
        if(!neg){
            int i = 0;
            while(str[i] == '0')
                i++;
           string t = str.substr(i+1);
           str = str[i];
            while(i--){
                str.push_back('0');
            }
            str = str+t;
        }
        
        for(int i = 0;i<str.size();i++){
            sum = sum*10 + (str[i] - '0');
        }
        return neg ? -sum : sum;

        
        
    }
};
