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

ll dist[1000];

int main()
{
    ll n,m,s,d,i,x,y;
    cin>>n>>m;
    vector<ll>n;
    f(i,0,m)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cin>>s>>d;
    f(i,0,1000)
    dist[i]=-1;
    queue<ll>q;
    q.push(s);
    dist[s]=0;
    while(q.empty()!=1)
    {
        x=q.front();
        q.pop();
        f(i,0,vec[x].size())
        {
            if(dist[vec[x][i]]==-1)
            {
                dist[vec[x][i]]=dist[x]+1;
                q.push(vec[x][i]);
            }
            
            
        }
    }
   cout<<dist[d]<<endl;
}


