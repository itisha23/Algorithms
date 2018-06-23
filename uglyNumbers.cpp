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
ll arr[501]; 
  

int main()
{
   ll t;
   t=1;
   cin>>t;
   while(t--)
   {
      ll n,count,p2,p3,p5,mini,a,b,c,i;
      cin>>n;
      set<ll>se;
      arr[0]=1;
      arr[1]=1;
      count=0;
      p2=1;p3=1;p5=1;
      while(count!=n)
      {
          a=arr[p2]*2;
          b=arr[p3]*3;
          c=arr[p5]*5;

          mini=min(a,min(b,c));
          arr[++count]=mini;

          if(mini==a)
          p2++;
          if(mini==b)
          p3++;
          if(mini==c)
          p5++;
       }
         cout<<arr[n]<<endl;
      }
      
     
   }
  
    
}


