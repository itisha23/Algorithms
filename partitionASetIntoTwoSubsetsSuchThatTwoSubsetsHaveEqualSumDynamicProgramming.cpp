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
        ll n,sum=0,i,j;
        cin>>n;
        ll arr[n];
        f(i,0,n)
        {
               cin>>arr[i];
               sum=sum+arr[i];
        }
       if(sum%2==1)
       cout<<"NO\n";
       else
       {
           sum=sum/2;
           bool dp[n][sum+1];
           f(i,0,n)
              f(j,0,sum+1)
                  dp[i][j]=0;
           i=n-1;
           for(j=0;j<=sum;j++)
           {
               dp[i][j]=0;
           }
           dp[i][0]=1;
           dp[i][arr[i]]=1;
           if(n>=2)
           {
                  for(i=n-2;i>=0;i--)
           {
              // cout<<i<<endl;
               for(j=0;j<=sum;j++)
               {
                   if(j==0)
                   dp[i][j]=1;
                   else if(j-arr[i]>=0)
                   {
                  dp[i][j]=dp[i+1][j]||dp[i+1][j-arr[i]];
                   }
                     else
                   {
                            dp[i][j]=dp[i+1][j];
                   }
                 
               }
           }
           }
        
          if(dp[0][sum])
           cout<<"YES\n";
           else
           cout<<"NO\n";
       }
      
    }
}


