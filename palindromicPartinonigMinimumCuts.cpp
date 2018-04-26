int Solution::minCut(string s) {
    
    int n=s.size(),i,j,k;
    int pd[n][n];
    for(i=n-1;i>=0;i--)
    {
        for(j=i;j<n;j++)
        {
            if((j-i)<=2)
            {
                if(s[i]==s[j])
                pd[i][j]=1;
                else
                pd[i][j]=0;
            }
            else
            {
                if(s[i]==s[j] && pd[i+1][j-1])
                pd[i][j]=1;
                else
                pd[i][j]=0;
            }
        }
    }
    int dp[n][n];
    for(i=n-1;i>=0;i--)
    {
        for(j=i;j<n;j++)
        {
            if(pd[i][j])
            dp[i][j]=0;
            else
            {
                dp[i][j]=INT_MAX;
                for(k=i;k<=j-1;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
            }
        }
    }
   // for(i=0;i<n;i++)
    return dp[0][n-1];
}
