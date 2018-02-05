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


