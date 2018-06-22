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

void increase(ll &ptr,ll a,set<ll>se)
{
    ptr++;
    while(se.find(arr[ptr]*a)!=se.end())
    {
        ptr++;
    }
}  
  

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
      arr[1]=1;arr[2]=2;arr[3]=3;arr[4]=4;arr[5]=5;arr[6]=6;arr[7]=8;arr[8]=9;arr[9]=10;arr[10]=12;
      se.insert(1);  se.insert(2);  se.insert(3);  se.insert(4);  se.insert(5);
      if(n<=10)
      cout<<arr[n]<<endl;
      else
      {
          count=10;
          p2=7;p3=5;p5=3;
          while(count!=n)
          {
              a=arr[p2]*2;
              b=arr[p3]*3;
              c=arr[p5]*5;
              
              mini=min(a,min(b,c));
              se.insert(mini);
              arr[++count]=mini;
          
              if(mini==a)
              increase(p2,2,se);
              if(mini==b)
              increase(p3,3,se);
              if(mini==c)
              increase(p5,5,se);
          }
         cout<<arr[n]<<endl;
      }
      
     
   }
  
    
}


