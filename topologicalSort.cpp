/*THERE IS NO NEED TO MAINTAIN VISITED ARRAY , YOU CAN IGNORE THAT BECAUSE IT IS A DAG */
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
vector<ll>adj[10005];
ll visited[10005];
ll print1[10005];

void iscycle(ll x,ll &d)
{
    ll i;
    visited[x]=1;
    for(i=0;i<vec[x].size();i++)
    {
        if(visited[vec[x][i]]==0)
        iscycle(vec[x][i],d);
        if(vec[x][i]==1 && vec[x][i]!=x)
          d=1;
    }
    
}

int main()
{
    ll n,m,i,x,y,ans=0,j,flag;
    cin>>n>>m;
    f(i,0,m)
    {
        cin>>x>>y;
       vec[x].push_back(y);
       adj[y].push_back(x);
    }
    iscycle(1,ans);
    if(ans==1)
    cout<<"Sandro fails.";
    else
    {
       ll indegree[n+1];
       f(i,1,n+1)
          visited[i]=0;

       f(i,1,n+1)
          print1[i]=0;
      
       f(i,1,n+1)
       indegree[i]=0;

       f(i,1,n+1)
           f(j,0,vec[i].size())
               indegree[vec[i][j]]++;

       priority_queue<ll,vector<ll>,greater<ll> >pq;
       queue<ll>q;

       f(i,1,n+1)
          if(indegree[i]==0)
              {
               pq.push(i);
              visited[i]=1;
              }

      //  f(i,1,n+1)
            //cout<<indegree[i]<<" ";
       
       /*f(i,1,n+1)
           {f(j,0,adj[i].size())
               cout<<adj[i][j]<<" ";cout<<endl;}*/
   
     while(pq.empty()!=1|| q.empty()!=1)
       {
           if(pq.empty()==1)
           {
               //cout<<"hi";
               pq.push(q.front());
               q.pop();
           }

           x=pq.top();
           print1[x]=1;
           cout<<x<<" ";
           pq.pop();
          
           f(i,0,vec[x].size())
           {
           // if(x==5)
             //cout<<vec[x][i]<<" ";
            //if(x==5)
             //cout<<indegree[vec[x][i]]<<" ";
             //if(x==5)
              //cout<<visited[vec[x][i]];
             if(visited[vec[x][i]]==0)
                  indegree[vec[x][i]]--;
            //if(x==5)
            //cout<<indegree[vec[x][i]]<<" ";
              
              if(indegree[vec[x][i]]==0 && visited[vec[x][i]]==0)
             {
                flag=0; 
               for(j=0;j<adj[vec[x][i]].size();j++)
                    {                                                 
                        if(print1[adj[vec[x][i]][j]]==0)
                                {
                                    flag=1;
                                    break;
                                    
                                }
                    } 
                           if(flag==0)
                             {
                                 pq.push(vec[x][i]);
                                 //cout<<x<<endl;
                                 
                             }
                        else
                               { q.push(vec[x][i]);
                                //cout<<"hi";
                                }
                     visited[vec[x][i]]=1;   
                    }
                 
             }    
          }
   }
    
  
}


