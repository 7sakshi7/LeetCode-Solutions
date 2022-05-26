class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>st;
        int maxCount = 0;
        for(int i=0;i<s.size();i++){
            if(st.empty()){ 
                
                st.push({s[i],i});
            }            
            else{
                if(s[i]==')' && st.top().first == '('){
                    pair<char,int>p = st.top();
                    st.pop();
                    
                    if(st.empty()){
                        maxCount = max(maxCount,i+1);
                    }
                    else{
                        maxCount = max(maxCount,i-st.top().second);
                    }
                }
                else
                    st.push({s[i],i});
            }
            
            // cout<<s[i]<<" "<<maxCount<<endl;
        }
        return maxCount;
    }

};
