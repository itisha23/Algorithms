//https://leetcode.com/problems/minimum-path-sum/submissions/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(),i,j;
        int n=grid[0].size();
            
        int dp[m][n];
        dp[m-1][n-1]=grid[m-1][n-1];
        
        i=m-1;
        for(j=n-2;j>=0;j--){
            dp[i][j]=grid[i][j]+dp[i][j+1];
        }
        
        j=n-1;
        for(i=m-2;i>=0;i--){
            dp[i][j]=grid[i][j]+dp[i+1][j];
        }
        
        for(i=m-2;i>=0;i--){
            for(j=n-2;j>=0;j--){
                dp[i][j]=grid[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
        
        return dp[0][0];
    }
};
