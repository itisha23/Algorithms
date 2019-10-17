//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll k,n,tn,i,j;
        cin>>tn>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        
        ll dp[tn+1][n];
        memset(dp,0,sizeof(dp));
        
        for(i=1;i<=tn;i++){
            for(j=1;j<n;j++){
                for(k=0;k<j;k++){
                    // if(j==n-1 && i==1 && k==2)
                    // cout<<arr[j]-arr[k]+dp[i-1][k]<<endl;
                  dp[i][j] = max(dp[i][j],(arr[j]-arr[k]+dp[i-1][k])) ;  
                }
               dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        
        // for(i=0;i<=tn;i++){
        //     for(j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<dp[tn][n-1]<<endl;
    }
}
