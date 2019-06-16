
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


int main(){
   ll n,m,i,j,k,x,y,wt;
   cin>>n>>m;
   vector<pair<ll,ll> >vec[n+1];
   f(i,0,m) {
       cin>>x>>y>>wt;
       vec[x].push_back(make_pair(y,wt));
   }
   ll dist[n+1];
   f(i,1,n+1)
   dist[i]=inf;
   for(k=1;k<=(n-1);k++){
        i=1;
       while(i<=n){
           for(j=0;j<vec[i].size();j++) {
               if(dist[vec[i][j].first]>dist[i]+vec[i][j].second);
                  dist[vec[i][j].first]=dist[i]+vec[i][j].second;
               
           }
           i++;
       }
   }
}
