#include<bits/stdc++.h>
using namespace std;


// Here the graph is represented as array of edges.


int main()
{
  cin>>n;
  ll g[m][n];
  f(i,0,n)
  {
    f(j,0,n)
      cin>>g[i][j];
  }

  ll dist[n][n];
  f(i,0,n)
    f(j,0,n)
      dist[i][j]=g[i][j];
   
  f(k,0,n)
  {
    f(i,0,n)
    {
        f(j,0,n)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k+1][j]);
    }
  }
}
