// 100%faster
class Solution {
public:
    string decodeString(string s) {
        stack<int>is;
        stack<char>cs;
        
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int sum = 0;
                while(isdigit(s[i])){
                    sum = sum*10 + s[i]-'0';
                    i++; 
                }
                i--;
                is.push(sum);
            }
            else if(s[i]=='['){
                if(i==0 || !isdigit(s[i-1])){
                    is.push(1);
                }
                
                cs.push(s[i]);
            }
            else if(s[i]==']'){
                string temp="";
                
                while(!cs.empty() && cs.top()!='['){
                    temp.push_back(cs.top());
                    cs.pop();
                }
                if(!cs.empty())
                    cs.pop();
                
                int x = is.top();
                is.pop();
                
                cout<<temp<<x<<endl;
                reverse(temp.begin(),temp.end());
                for(int j=0;j<x;j++){
                    for(int k=0;k<temp.size();k++){
                        cs.push(temp[k]);
                    }
                }
                cout<<cs.size()<<endl;
            }
            else
                cs.push(s[i]);
            
        }
        
        string str="";
        while(!cs.empty()){
            str.push_back(cs.top());
            cs.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
