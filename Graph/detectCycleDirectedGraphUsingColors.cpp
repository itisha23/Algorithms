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

vector<ll>vec[10005];
ll d=0;
 set<ll>white;
 set<ll>gray;
 set<ll>black;
    
ll dfs(ll x)
{
    ll i;
    gray.insert(x);
    white.erase(white.find(x));
    for(i=0;i<vec[x].size();i++)
    {
        if(white.count(vec[x][i]))
           d=d|dfs(vec[x][i]);
        if(gray.count(vec[x][i]))
             d=1;
    }
    black.insert(x);
    gray.erase(gray.find(x));
    return d;
}

ll iscycle(ll n)
{
    ll a=0,i;
   
   for(i=0;i<n;i++)
      white.insert(i);
   while(white.size()!=0)
   {
       a=dfs(*white.begin());
   }
      return a;
}


int main()
{
    ll n,m,i,x,y;
    cin>>n>>m;
    f(i,0,m)
    {
       cin>>x>>y;
       vec[x].push_back(y);
    }
   d=iscycle(n);
   if(d==1)
    cout<<"Cycle";
   else
     cout<<"no cycle";
}


detec
