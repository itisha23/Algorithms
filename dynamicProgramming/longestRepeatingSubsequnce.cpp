int Solution::anytwo(string s) {
    
    int n=s.size(),i,j;

    int lcs[n+1][n+1];
    for(i=0;i<=n;i++)
      lcs[n][i]=0;
    for(i=0;i<=n;i++)
      lcs[i][n]=0;
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(s[i]==s[j]&& i!=j)
               lcs[i][j]=lcs[i+1][j+1]+1;
            else
                lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
        }
    }
    if(lcs[0][0]<2)
     return 0;
    else
 return lcs[0][0];
}
