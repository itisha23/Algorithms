#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main() {
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size(), i, j,l;
        ll dp[n][n];
        
    
        f(i,0,n){
            dp[i][i]=0;
        }
        
        for(i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1]=0;
            } else {
                dp[i][i+1]=1;
            }
        }
        
        for(l=3; l<=n; l++){
            for(i=0; i<=n-l; i++){
                j=i+l-1;
                
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
                }
            }
        }
        
        cout<<dp[0][n-1]<<endl;
    }
}