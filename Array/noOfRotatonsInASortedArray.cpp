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
      ll n,i,start,end,mid,flag=0,ind;
      cin>>n;
      ll arr[n];
      f(i,0,n)
      cin>>arr[i];
      f(i,0,n-1)
      {
          if(arr[i]>arr[i+1])
          {
              ind=i;
              flag=1;
              break;
          }
      }
      if(flag)
      cout<<ind+1<<endl;
      else
      cout<<0<<endl;

    }
}


