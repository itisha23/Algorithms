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

void dfs(ll pa,ll s,ll visited[],ll &flag)
{
   ll i,a;
   visited[s]=1;
   f(i,0,vec[s].size())
   {
    a=vec[s][i];
    if(visited[a]==0)
    {
     dfs(s,a,visited,flag);
       
    }
    else if(visited[a]==1)
    {
       if(pa!=a)
       flag=1;
    }
  }
  
}

int main()
{
   freopen("inp.in","r",stdin);
      
    ll n,m,x,y,i,flag=0;
    cin>>n>>m;
    f(i,0,m)
    {
       cin>>x>>y;
       vec[x].push_back(y);
       vec[y].push_back(x);
    }
    ll visited[n];
    f(i,0,n)
     visited[i]=0;
   x=0;
    f(i,0,n)
    {
      if(visited[i]==0)
      {
        dfs(-1,i,visited,flag);
        if(flag==1)
         break;
      }
    }
   if(flag==1)
    cout<<"Cycle is Present";
   else
     cout<<"Cycle is not present";
}


