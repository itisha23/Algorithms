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

vector<ll>vec[20];
ll a;
ll maxcount=INT_MIN;
ll visited[20];

void dfs(ll s,ll count)
{
   ll i;
   visited[s]=1;
   f(i,0,vec[s].size())
   {
      if(!visited[vec[s][i]])
       {
         
         if(count+1>maxcount)
           {
              a=vec[s][i];
              maxcount=count+1;
           }
          dfs(vec[s][i],count+1);
       }
   }
}
int main()
{  
ll n,m,i,x,y;
cin>>n>>m;
f(i,0,m)
{
   cin>>x>>y;
   vec[x].push_back(y);
   vec[y].push_back(x);
} 

f(i,0,20)
visited[i]=0;
dfs(1,1);

maxcount=INT_MIN;

f(i,0,20)
visited[i]=0;
//cout<<a<<endl;
dfs(a,1);
//cout<<a<<endl;
cout<<maxcount;
}


