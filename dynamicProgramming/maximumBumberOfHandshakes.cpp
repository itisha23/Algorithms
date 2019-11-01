#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,j;
        cin>>n;
        n=n/2;
        
        ll dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(i=2;i<=n;i++){
            for(j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        // for(i=0;i<=n;i++){
        //     cout<<dp[i]<<" "; 
        // }
        // cout<<endl;
        cout<<dp[n]<<endl;
    }
}
