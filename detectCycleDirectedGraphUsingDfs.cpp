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

vector<ll>vec[100];

ll dfs(ll s,ll visited[],ll recst[])
{
   ll i,a;
  if(visited[s]==0)
    {
     visited[s]=1;
     recst[s]=1;
    }
  f(i,0,vec[s].size())
   {
     
  
      a=vec[s][i];
       if(s==3)
       cout<<a<<endl;
      if(visited[a]==0)
        {
          if(dfs(a,visited,recst)==1)
           return 1;
        }
      else if(visited[a]==1)
        {
          if(recst[a]==1)
            return 1;
        }
   }
    recst[s]=0;
   return 0;
    
}

int main()
{
   freopen("inp.in","r",stdin);
      
    ll n,m,x,y,i;
    cin>>n>>m;
    f(i,0,m)
    {
       cin>>x>>y;
       vec[x].push_back(y);
      
    }

    ll visited[n];ll recst[n];
    f(i,0,n)
     visited[i]=0;
    f(i,0,n)
     recst[i]=0;
      x=0;
    for(i=0;i<n;i++)
    {
         if(visited[i]==0)
         {
         x=dfs(i,visited,recst);
         if(x==1)
         {
           cout<<"Cycle is present\n";
             break;
         }

         }
    }
       if(x==1)
          cout<<"Cycle is present\n";
       else
           cout<<"Cycle is not present\n";
         
 }

