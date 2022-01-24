class Solution {
public:
    int longestPalindromeSubseq(string s) {
         int n = s.size();
        int dp[n+1][n+1];
        
        string str = s;
        reverse(str.begin(),str.end());
        
        memset(dp,0,sizeof(dp));
        int ans = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == str[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                    
            }
        }
        return ans;
    }
};
