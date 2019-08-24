https://leetcode.com/problems/unique-paths/submissions/

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        int i,j;
        
        i=m-1;
        for(j=0;j<n;j++)
            dp[i][j]=1;
        
        j=n-1;
        for(i=0;i<m-1;i++)
            dp[i][j]=1;
        
        for(i=m-2;i>=0;i--){
            for(j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
        
    }
};
