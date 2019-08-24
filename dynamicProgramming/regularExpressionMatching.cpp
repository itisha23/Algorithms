class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m=s.size(),i,j;
        int n=p.size();
        
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=1;
        j=0;
        for(i=1;i<=m;i++)
            dp[i][j]=0;
        
        //ZERO OCCURENCE CASE
        i=0;
        for(j=1;j<=n;j++){
            if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
            }
        }
        
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                
              if(s[i-1] == p[j-1] || p[j-1]=='.'){
                  dp[i][j]=dp[i-1][j-1];
              }
             else if(p[j-1] =='*'){
                 if(s[i-1] == p[j-2] || p[i-1]=='.')
                     dp[i][j]=dp[i-1][j];
                 dp[i][j]=dp[i][j] || dp[i][j-2];
             }
            }
        }
        
        return dp[m][n];
        
    }
};
