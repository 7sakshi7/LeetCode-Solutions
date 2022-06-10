class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        
        for(int i = 0;i<path.size();i++){
            if(path[i] =='/')
                continue;
            else if(path[i] == '.'){
                int c = 0,j = i;
                bool alpha = 0;
                while(i<path.size() && path[i] != '/'){
                    if(isalpha(path[i]))
                        alpha = 1;
                    i++;
                    c++;
                }
                i--;
                if(c == 2){
                    if(alpha){
                        st.push(path.substr(j,i-j+1));
                        cout<<st.top()<<" ";
                    }
                    else if(!st.empty())
                        st.pop();
                }
                else if(c >2){
                    st.push(path.substr(j,i-j+1));
                    cout<<st.top()<<" ";
                }
            }
            
            else{
                int j = i;
                while(i<path.size() && path[i] != '/'){
                    i++;
                }
                i--; 
                st.push(path.substr(j,i-j+1));
                cout<<st.top()<<" ";
            }
        }
        
        string str = "";
        vector<string>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        for(int i = v.size()-1;i>=0;i--){
            str+="/";
            str+=v[i];
        }
        return str  == "" ? "/" : str;
    }
};
