/*Author ITISHA GUPTA (NITP) */


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

int main()
{
  // freopen("inp.in","r",stdin);
      
    ll n,m,x,y,i,j,a;
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
  stack<ll>st;
  st.push(0);
  while(st.empty()!=1)
  {
     a=st.top();
     st.pop();
     if(visited[a]==0)
     {
           visited[a]=1;
           cout<<a<<" ";
     }
     f(i,0,vec[a].size())
     {
          if(visited[vec[a][i]]==0)
             st.push(vec[a][i]);
     }
  }

   
}


