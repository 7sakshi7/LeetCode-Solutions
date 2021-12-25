class Solution {
public:
    int calculate(string s) {
        stack<char>st;
        bool op = 0;
        for(int i=0;i<s.size();i++){            
            if(s[i] == ' ')continue;
            if(s[i] == '*'){
                op = 1;
                int firstNumber = 0,index = 1;
               while(!st.empty() && isdigit(st.top())){
                    firstNumber += (st.top() - '0')*index;
                    index*=10;
                    st.pop();
                }
                
                while(s[i+1] == ' ')
                    i++;
                
                index = 1;
                int secondNumber = 0;
                while(isdigit(s[i+1])){
                    secondNumber = secondNumber*10 + (s[i+1]-'0');
                    i++;
                }
                
                int ans = firstNumber*secondNumber;
                if(ans>=0 && ans<=9)
                st.push(ans + '0');
                else{
                    string r = to_string(ans);
                    for(auto it : r)
                        st.push(it);
                }
                // i++;
                // cout<<s[i]<<endl;
            }
           
            else if(s[i] == '/'){
                op = 1;
                int firstNumber = 0,index=1;
               while(!st.empty() && isdigit(st.top())){
                    firstNumber += (st.top() - '0')*index;
                    index*=10;
                    st.pop();
                }
                
                while(s[i+1] == ' ')
                    i++;
                
                index = 1;
                int secondNumber = 0;
                while(isdigit(s[i+1])){
                    secondNumber = secondNumber*10 + (s[i+1]-'0');
                    i++;
                }
                 
                int ans = firstNumber/secondNumber;
               if(ans>=0 && ans<=9)
                st.push(ans + '0');
                else{
                    string r = to_string(ans);
                    for(auto it : r)
                        st.push(it);
                }
                // i++;
            }
            else
            {
                st.push(s[i]);
                if(!isdigit(s[i]))
                    op = 1;
            }
           
        }
        cout<<endl;
        
        if(!op){
            return stoi(s);
        }
        int ans = 0;
       
        stack<char>q;
        while(!st.empty()){
            cout<<st.top()<<" ";
            q.push(st.top());
            st.pop();
        }
        
        while(!q.empty()){
            bool neg = 0;
            if(q.top() == '-'){
                neg = 1;
                q.pop();
            }
                
            int firstNumber = 0;
            while(!q.empty() && isdigit(q.top())){
                firstNumber = firstNumber*10 + (q.top() - '0');
                q.pop();
            }
            
            if(neg){
                neg = 0;
                firstNumber = -firstNumber;
            }
            
            if(q.empty())return firstNumber;
            
            char op = q.top();
            q.pop();
            
            if(op == '-')
                neg = 1;
            int secondNumber = 0;
            while(!q.empty() && isdigit(q.top())){
                secondNumber = secondNumber*10 + (q.top() - '0');
                q.pop();
            }
            
             if(neg){
                 secondNumber = -secondNumber;
             }
           
                int res = firstNumber + secondNumber;
                if(q.empty()) return res;
                if((res>=-9 && res<=9)){ 
                    q.push(abs(res)+'0');
                }
                else{
                    string temp = to_string(abs(res));
                    reverse(temp.begin(),temp.end());
                    for(auto it : temp)
                        q.push(it);
                }
                
                if(res<0)
                    q.push('-'); 
        }
        return 0;
   }
};
