#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
#define fi first
#define se second
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld",a)

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;

vector<ll>vec[100005];
ll visited[100005];

void countPathsUtil(ll u, ll d,
                           ll &pathCount)
{
    ll i;
    visited[u] = true;
    if (u == d)
        pathCount=pathCount+1;
    else 
    {
        for (i=0;i<vec[u].size(); ++i)
            if (!visited[vec[u][i]])
                countPathsUtil(vec[u][i], d,pathCount);
    }
    visited[u] = false;
}

ll countPaths(ll s, ll d)
{
    ll pathCount = 0;
    countPathsUtil(s, d, pathCount);
    return pathCount;
}


int main()
{
  fast;
  ll t;
  cin>>t;
  while(t--)
  {
      ll n,e,s,d,i,x,y;
      cin>>n>>e>>s>>d;
      f(i,1,n+1)
      vec[i].clear();
      f(i,1,n+1)
      visited[i]=0;
      f(i,0,e)
      {
          cin>>x>>y;
          vec[x].push_back(y);
      }
      ll ans=countPaths(s,d);
      cout<<ans<<endl;
  }
}
