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
       ll n,i,tot=0,mini=INT_MAX,j;
       cin>>n;
       ll arr[n];
       f(i,0,n)
       {
           cin>>arr[i];
           tot+=arr[i];
       }
       if(n==1)
       cout<<arr[0]<<endl;
       else
       {
           bool dp[n][tot+1];
            i=n-1;
          for(j=0;j<=tot;j++)
               dp[i][j]=0;
         dp[i][0]=1;
         dp[i][arr[i]]=1;
        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<=tot;j++)
            {
                if(j==0)
                dp[i][j]=1;
                if(j-arr[i]>=0)
                dp[i][j]=dp[i+1][j]||dp[i+1][j-arr[i]];
                else
                dp[i][j]=dp[i+1][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=tot;j++)
            {
                if(dp[i][j])
                mini=min(mini,abs(2*j-tot));
            }
        }
        cout<<mini<<endl;
       }
     
      
     
      
   }
}


