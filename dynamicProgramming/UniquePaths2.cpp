https://leetcode.com/problems/unique-paths-ii/submissions/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        long long int m=obstacleGrid.size(),i,j;
        long long int n=obstacleGrid[0].size();
        
        long long int dp[m][n];
        
        memset(dp,0,sizeof(dp));
      
        if(obstacleGrid[m-1][n-1]!=1)
        dp[m-1][n-1]=1;
        
        i=m-1;
        for(j=n-2;j>=0;j--){
            if(obstacleGrid[i][j]!=1)
                dp[i][j]=dp[i][j+1];
        }
        
        j=n-1;
        for(i=m-2;i>=0;i--){
            if(obstacleGrid[i][j]!=1)
                dp[i][j]=dp[i+1][j];
        }
        
        for(i=m-2;i>=0;i--){
            for(j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]!=1)
                    dp[i][j]=dp[i+1][j];
                if(obstacleGrid[i][j]!=1)
                    dp[i][j]+=dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};
