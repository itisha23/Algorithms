#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
#define fi first
#define se second

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;





int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
      ll n,i,j,cost;
      cin>>n;
      ll arr[n];
      f(i,0,n)
       cin>>arr[i];
     // ll cost;
      cin>>cost;
      ll dp[n+1][cost+1];
      i=n;
      for(j=0;j<=cost;j++)
        dp[i][j]=0;
      j=0;
      for(i=0;i<=n;i++)
      dp[i][j]=1;
      
      for(i=n-1;i>=0;i--)
      {
          for(j=0;j<=cost;j++)
          {
              if(j-arr[i]>=0)
              dp[i][j]=dp[i][j]-arr[i]]+dp[i+1][j];
              else
              dp[i][j]=dp[i+1][j];
          }
      }
      cout<<dp[0][cost]<<endl;
  }

}
