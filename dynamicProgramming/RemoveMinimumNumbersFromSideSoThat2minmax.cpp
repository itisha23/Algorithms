#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    
    ll t;
    cin>>t;
    while(t--){
        ll n,i,j,k,mini,maxi,l;
        cin>>n;
        ll arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        ll dp[n][n];
        for(i=0;i<n;i++)
            dp[i][i]=0;
        for(l=2;l<=n;l++){
            for(i=0;i<=n-l;i++){
                j=i+l-1;
                
                mini=INT_MAX,maxi=INT_MIN;
                for(k=i;k<=j;k++){
                    mini= min(mini,arr[k]);
                    maxi = max(maxi,arr[k]);
                }
                
                if(2*mini > maxi){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j] = 1+ min(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        
        
        cout<<dp[0][n-1]<<endl;
    }
}
