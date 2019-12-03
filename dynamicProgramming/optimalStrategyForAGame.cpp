#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

int main(){
        
        ll t;
        cin>>t;
        while(t--){
            ll n,i,j,l;
            cin>>n;
            ll arr[n];
            f(i,0,n)
                cin>>arr[i];
            
            vector<pair<ll,ll> >dp[n];
            f(i,0,n)
                dp[i].resize(n);
            f(i,0,n)
                dp[i][i] = make_pair(arr[i],0);
            
            for(l=2;l<=n;l++){
                for(i=0;i<=n-l;i++){
                    j=i+l-1;
                    
                    if(arr[i]+dp[i+1][j].second > arr[j]+dp[i][j-1].second){
                        dp[i][j] =  make_pair(arr[i]+dp[i+1][j].second, dp[i+1][j].first);
                    }
                    else{
                        dp[i][j] = make_pair(arr[j]+dp[i][j-1].second, dp[i][j-1].first);
                    }
                    
                }
            }
            
            cout<<dp[0][n-1].first<<endl;
        }
}
