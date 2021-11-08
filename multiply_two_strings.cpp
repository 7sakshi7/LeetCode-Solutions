#include<bits/stdc++.h>
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(),m=num2.size();
        
        if(num1=="0" || num2=="0")return "0";
        
        int totalSum = 0;
        vector<string>v;
        for(int i=n-1;i>=0;i--){
            int carry = 0;
            int sum = 0;
            string storeSum = "";
            for(int j=m-1;j>=0;j--){
                sum = (num1[i]-'0')*(num2[j]-'0')+carry;
                storeSum.push_back((sum%10)+'0');
                carry = sum/10;
            }
            if(carry)
            storeSum.push_back(carry+'0');
            reverse(storeSum.begin(),storeSum.end());
            for(int j = i;j<n-1;j++){
                storeSum.push_back('0');
            }
            v.push_back(storeSum);
        }
        
       string str = v[0];
        for(int i=1;i<v.size();i++){
            string s = v[i];
            string t = "";
            int j = str.size()-1,k=s.size()-1;
            int carry = 0,sum=0;
            while(j>=0 && k>=0){
                sum = (str[j]-'0')+(s[k]-'0')+carry;
                cout<<sum<<" ";
                t.push_back((sum%10)+'0');
                carry = sum/10;
                j--;
                k--;
            }
            
            while(j>=0){
                sum = (str[j]-'0')+carry;
                t.push_back((sum%10)+'0');
                carry = sum/10;
                j--;
            }
            while(k>=0){
                sum = (s[k]-'0')+carry;
                t.push_back((sum%10)+'0');
                carry = sum/10;
                k--;
            }
            
            if(carry)
                t.push_back(carry+'0');
            
            reverse(t.begin(),t.end());
            str = t;
            cout<<str<<endl;
        }
        
        return str;
       
    }
};