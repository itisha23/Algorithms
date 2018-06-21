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
  ll n;
  cin>>n;
  ll arr[n];
  f(i,0,n)
    cin>>arr[i];
  if(n<k<0)
    return "Not Pssible";
 
  f(i,0,k)
  w+=arr[i];
  
  ans=w;
  f(i=k;i<n;i++)
  {
     w=w+arr[i]-arr[i-k];
     ans=max(ans,w);
  }
  cout<<ans;
}
    
