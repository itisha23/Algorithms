#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
//#define fi first
#define se second

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;





int main()
{
   ll t;
   t=1;
   cin>>t;
   while(t--)
   {
      ll n,i,sum=0,mini,a,ans;  
      cin>>n;
      ll arr[n];
      f(i,0,n)
      cin>>arr[i];
      ll left[n];ll right[n];ll fi=-1;ll li=-1;left[0]=fi;left[n-1]=fi;right[0]=-1;right[n-1]=-1;
      if(arr[0]!=0)
       fi=0;
      if(arr[n-1]!=0)
       li=n-1;
      
      f(i,1,n-1)
      {
          left[i]=fi;
          if(arr[i]!=0 && fi ==-1 )
          fi=i;
          else if(arr[i]!=0  && arr[i]>arr[fi])
            fi=i;
      }
      for(i=n-2;i>=1;i--)
      {
          right[i]=li;
          if(arr[i]!=0 && li==-1)
          li=i;
          else if(arr[i]!=0 && arr[i]>arr[li])
           li=i;
           //else
           
      }
      f(i,1,n-1)
      {
          if(left[i]!=-1 && right[i]!=-1)
          {
              mini=min(arr[left[i]],arr[right[i]]);
              
              if(arr[i]<mini)
               sum+=mini-arr[i];
              
          }
      }
      cout<<sum<<endl;
      
   }
  
    
}


