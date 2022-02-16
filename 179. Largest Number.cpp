class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        
        vector<string>res(n);
        
        for(int i = 0;i<n;i++){
            res[i] = to_string(nums[i]);
        }
        
       for(int i = 1;i<n;i++){
           int j =i-1;
           string temp = res[i];
           while(j>=0){
               string s = (res[j]+temp);
               // long long int sx = stoi(s);
               
               string st = temp+res[j];
               // long long int stx = stoi(st);
               
               if(s[0]-'0'>st[0]-'0')
                   break;
               else if(s[0]-'0' == st[0]-'0'){
                   int k = 1,l = 1;
                   bool f = 1;
                   while(k<s.size() && l<st.size()){
                       if(s[k]-'0'>st[l]-'0'){
                           f = 0;
                           break;
                       }
                       else if(s[k]-'0'<st[l]-'0'){
                           break;
                       }
                       k++;
                       l++; 
                   }
                   if(!f)
                       break;
               }
               res[j+1] = res[j];
               j--;
           }
           res[j+1] = temp;
       }
        
        string str = "";
        for(int i = 0;i<n;i++){
            str = str+res[i];
        }
        if(str[0] == '0'){
            int j = 0;
            while(j<str.size() && str[j] == '0')
                j++;
            
            if(j == str.size())
                return "0";
            str = str.substr(0,j);
            
        }
        return str;
        
    }
};
