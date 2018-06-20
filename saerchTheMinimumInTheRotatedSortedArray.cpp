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
      ll n,ind=-1,l,h,mid,i;
      cin>>n;
      ll arr[n];
      f(i,0,n)
       cin>>arr[i];
       l=0;h=n-1;
       while(l<=h)
       {
           mid=(l+h)/2;
           if(mid-1>=0 && arr[mid]<arr[mid-1])
             {
                 ind=mid;
                 break;
             }
             else if(arr[mid]>arr[h])
             l=mid+1;
             else
             h=mid-1;
           
       }
       if(ind!=-1)
       cout<<arr[ind]<<endl;
       else
       cout<<arr[0]<<endl;
  }
    
}
