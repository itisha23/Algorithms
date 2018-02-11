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
    ll n,m,x,y,w,wt,ver,i,sum=0;
    cin>>n>>m;
    vector<pair<ll,ll> >vec[n+1];
    f(i,0,m) {
        cin>>x>>y>>w;
        vec[x].push_back(make_pair(y,w));
        vec[y].push_back(make_pair(x,w));
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
    ll visited[n+1];
    f(i,1,n+1)
    visited[i]=0;
    pq.push(make_pair(0,1));
    visited[1]=1;
    pair<ll,ll>p;
    while(pq.empty()!=1)
    {
        p=pq.top();
        pq.pop();
        wt=p.first;
        ver=p.second;
        if(visited[ver]==1)
          continue;
        sum+=wt;
        visited[ver]=1;
        for(i=0;i<vec[ver].size();i++)
        {
            if(visited[vec[ver][i].first]==0)
            pq.push(make_pair(vec[ver][i].second,vec[ver][i].first));
        }
    }
   cout<<sum;
}


