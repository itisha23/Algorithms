/* AUTHOR -ITISHA GUPTA(NITP) */
/*TIME COMPLEXITY(O(V(E+V)))

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
ll n;
ll tc[100][100];

void trans(ll s,ll v)
{
   
    ll i;
    tc[s][v]=1;
    f(i,0,vec[v].size())
     {
         
        if(tc[s][vec[v][i]]==0)
          trans(s,vec[v][i]);
     }
}

int main()
{
      
    ll m,x,y,i,j;
    cin>>n>>m;
    f(i,0,m)
    {
       cin>>x>>y;
       vec[x].push_back(y);
    }
    f(i,0,n)
     f(j,0,n)
       tc[i][j]=0;
    
    f(i,0,n)
    {
      trans(i,i);
    }
  
   
    f(i,0,n)
     {
       f(j,0,n)
         cout<<tc[i][j]<<" ";
       cout<<endl;
     }
}


