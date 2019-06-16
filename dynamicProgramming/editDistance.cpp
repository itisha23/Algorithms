int Solution::minDistance(string str1, string str2) {
    
    
    int m=str1.size();
    int n=str2.size();
     int dp[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
       {
            if (i==0)
                dp[i][j] = j;
            else if (j==0)
                dp[i][j] = i; 
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   min(dp[i-1][j],  // Remove
                                   dp[i-1][j-1])); // Replace
        }
    }
 
    return dp[m][n];
}
