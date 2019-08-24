class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m=s.size(),i,j;
        int n=p.size();
        
        int dp[m+1][n+1];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=1;
        
        //PAT is zero-already set to zero
        
        //string is zero
        i=0;
        for(j=1;j<=n;j++){
            if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-1];//ignore the char all together
            }
        }
        
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(s[i-1] == p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1] =='*'){
                    dp[i][j]=dp[i][j-1]|dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};
