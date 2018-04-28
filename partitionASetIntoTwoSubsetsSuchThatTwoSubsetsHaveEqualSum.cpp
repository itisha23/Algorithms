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

int func(ll i,ll n,ll arr[],ll sum)
{
   // cout<<"hi";
    if(sum==0)
    return 1;
    if(i==n)
    return 0;
    else if(arr[i]>sum)
    return func(i+1,n,arr,sum);
    else
    return (func(i+1,n,arr,sum-arr[i])||func(i+1,n,arr,sum));
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0,i,a;
        cin>>n;
        ll arr[n];
        f(i,0,n)
        {
               cin>>arr[i];sum=sum+arr[i];
        }
       if(sum%2==1)
       cout<<"NO\n";
       else
       {
           sum=sum/2;
             a=func(0,n,arr,sum);
             if(a)
             cout<<"YES\n";
             else
             cout<<"NO\n";
       }
      
    }
}


