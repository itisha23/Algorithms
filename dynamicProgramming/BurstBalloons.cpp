
//https://leetcode.com/problems/burst-balloons/submissions/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size(),i,j,k,x,y,l;
        
        if(n==0)
            return 0;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(l=1;l<=n;l++){
            for(i=0;i<=n-l;i++){
                j=i+l-1;
                
                for(k=i;k<=j;k++){
                    
                    x= nums[k];
                    if(i-1>=0)
                        x=x*nums[i-1];
                    if(j+1<n)
                        x=x*nums[j+1];
                    
                    if(k-1>=0 && k+1<n)
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+x);
                    else if(k-1>=0)
                        dp[i][j]=max(dp[i][j],dp[i][k-1]+x);
                    else if(k+1<n)
                        dp[i][j]=max(dp[i][j],dp[k+1][j]+x);
                    else
                        dp[i][j]=max(dp[i][j],x);
                }
            }
        }
        return dp[0][n-1];
    }
};
