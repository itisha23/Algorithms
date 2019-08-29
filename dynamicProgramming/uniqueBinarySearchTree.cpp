//https://leetcode.com/problems/unique-binary-search-trees/submissions/


class Solution {
public:
    int numTrees(int n) {
        
        if(n==0 || n==1)
            return 1;
        int dp[n+1];
        
        int i,j;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        
        for(i=2;i<=n;i++){
            
            for(j=0;j<i;j++){
                
                dp[i]+=dp[j]*dp[(i-j-1)];
            }
            //cout<<dp[i]<<endl;
        }
        
        return dp[n];
        
    }
};
