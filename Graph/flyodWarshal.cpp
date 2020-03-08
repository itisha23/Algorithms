#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)


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
        if(dist[i][k] != INF && dist[k+1][j]!= INF) { // To avoid overflow.
          dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
        
    }
  }
}

//Also, the value of INF can be taken as INT_MAX from limits.h to make sure that we handle maximum possible value. When we take INF as INT_MAX, we need to change the if condition in the 
//above program to avoid arithmetic overflow.