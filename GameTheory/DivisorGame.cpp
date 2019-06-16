/* https://leetcode.com/problems/divisor-game/*/

class Solution {
public:
    bool divisorGame(int N) {
        
        int dp[N+1];
        memset(dp,0,sizeof(dp));
        
        int i,x;
        
        dp[1]=0;
        
        for(i=2;i<=N;i++){
            
            for(x=1;x<i;x++){
                if(i%x==0){
                    dp[i]=dp[i]|(!dp[i-x]);
                }
            }
        }
        
        return dp[N];
    }
};
