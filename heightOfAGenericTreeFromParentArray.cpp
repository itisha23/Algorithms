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

int main()
{
  ll n,i,c,count=0,key,a;
  cin>>n;
  ll p[n];
  f(i,0,n)
   cin>>p[i];
  ll visited[n];
  f(i,0,n)
   visited[i]=0;
  map<ll,vector<ll> >mp;
  f(i,0,n)
  {
    key=p[i];
    mp[key].push_back(i);
  }

   queue<ll>q;
   q.push(-1);
   while(q.empty()!=1)
   {
      c=q.size();
      while(c--)
      {
         a=q.front();
         q.pop();
         for(i=0;i<mp[a].size();i++)
            q.push(mp[a][i]);
      }
      count++;
   }
   cout<<count-1<<endl;
}
