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
      ll n,k,i,ind;
      cin>>n>>k;
      ll arr[n];
      f(i,0,n)
      {
          cin>>arr[i];
      }
      k=k%n;
      ll temp[n];
      f(i,0,n)
      {
          ind=(i%n-(k%n)+n)%n;
          temp[ind]=arr[i];
      }
      f(i,0,n)
      cout<<temp[i]<<" ";
      cout<<endl;
    
  }
}


