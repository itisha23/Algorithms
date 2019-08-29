class Solution {
public:
    int numDecodings(string s) {
        
       long long int n=s.size(),i;
        if(n==0)
            return 0;
        long long int dp[n+1];
        memset(dp,0,sizeof(dp));
        if(s[n-1]!='0')
        dp[n-1]=1;
        else
            dp[n-1]=0;
        dp[n]=1;
        
        for(i=n-2;i>=0;i--){
                if(s[i]=='1'||( s[i]=='2' && s[i+1]<'7') )
                    dp[i]=dp[i+2];
                if(s[i]>'0')
                    dp[i]+=dp[i+1];
            
        }
        
        return dp[0];
    }
};
