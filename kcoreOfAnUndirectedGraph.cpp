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
   freopen("inp.in","r",stdin);
      
    ll n,m,x,y,i,j,s,k;
    cin>>n>>m>>k;
    f(i,0,m)
    {
       cin>>x>>y;
       vec[x].push_back(y);
       vec[y].push_back(x);
    }
  
   ll indegree[n];
   ll removed[n];
   vector<ll>::iterator it;
   f(i,0,n)
     indegree[i]=0;
   f(i,0,n)
     removed[i]=0;
   f(i,0,n)
       f(j,0,vec[i].size())
         indegree[vec[i][j]]++;
    queue<ll>q;
   f(i,0,n)
   if(indegree[i]<k)
    q.push(i);
   while(q.empty()!=1)
   {
      s=q.front();
      q.pop();
      removed[s]=1;
      f(i,0,vec[s].size())
      {
        if(removed[vec[s][i]]==0)
          { it=find(vec[vec[s][i]].begin(),vec[vec[s][i]].end(),s);
               vec[vec[s][i]].erase(it);
               indegree[vec[s][i]]--;
                if(indegree[vec[s][i]]<k)
                   q.push(vec[s][i]);
               
          }
        
      }
      vec[s].clear();
   }
     f(i,0,n)
     {
          if(vec[i].size()!=0)
          {
              cout<<i<<": ";
              f(j,0,vec[i].size())
                cout<<vec[i][j]<<" ";
               cout<<endl;
         
          }
           
     }
}


