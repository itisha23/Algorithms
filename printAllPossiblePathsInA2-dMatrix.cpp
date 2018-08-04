#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf INT_MAX-1
#define pb push_back
#define fi first
#define se second

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;


void func(vector<pair<int,int> >&v,int mat[][3],int i,int j,int m,int n)
{
      if(i==m-1 && j==n-1)
     {
         for(i=0;i<v.size();i++)
         {
             cout<<mat[v[i].first][v[i].second]<<" ";
          
         }
        cout<<endl;
     }
     
    if(j+1<n)
      {
        v.push_back(make_pair(i,j+1));
       func(v,mat,i,j+1,m,n);
        v.pop_back();
      }
   if(i+1<m)
   {
          v.push_back(make_pair(i+1,j));
       func(v,mat,i+1,j,m,n);
        v.pop_back();
   }
 //v.pop_back();
}
int main()
{
   int mat[2][3]={{1,2,3},{4,5,6}};
   vector<pair<int,int> >v;
   v.push_back(make_pair(0,0));
   func(v,mat,0,0,2,3);
}


