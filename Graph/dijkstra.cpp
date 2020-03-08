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


int main()
{
    ll n,e,s,i,x,y,wt;
    cin>>n>>e>>s;
    vector<pair<ll,ll> >vec[n+1];
    f(i,0,e){
        cin>>x>>y>>wt;
        vec[x].push_back(make_pair(y,wt));
        vec[y].push_back(make_pair(x,wt));
    }
    ll dist[n+1];
    ll vis[n+1];
    f(i,1,n+1)
    dist[i]=inf;
    f(i,1,n+1)
      vis[i]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
    pq.push(make_pair(0,s));
    dist[s]=0;
    pair<ll,ll>p,p1;
    while(pq.empty()!=1)
    {
        p=pq.top();
        pq.pop();
        vis[p.second]=1;
        for(i=0;i<vec[p.second].size();i++)
        { 
            p1=vec[p.second][i];
            if(vis[p1.first]==0)
            {
               if(dist[p1.first]>dist[p.second]+p1.second)
                      {
                         dist[p1.first]=dist[p.second]+p1.second;
                          pq.push(make_pair(dist[p1.first],p1.first));
                      }
                          
            }
     }
    }
    f(i,1,n+1)
    cout<<dist[i]<<" ";
    
   
}


