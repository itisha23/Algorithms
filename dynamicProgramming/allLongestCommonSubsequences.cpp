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

ll dp[100][100];
void func(ll i,ll j,ll m,ll n,string s1,string s2,string s,set<string>&se)
{
   // cout<<i<<" "<<j<<endl;
    if(i==m || j==n || dp[i][j]==0)
    {
      
        if(s.size()!=0)
        se.insert(s);
    }
    else if(s1[i]==s2[j])
    {
        s=s+s1[i];  //cout<<s<<endl;
        func(i+1,j+1,m,m,s1,s2,s,se);
    }
    else if(dp[i+1][j]>dp[i][j+1])
    func(i+1,j,m,n,s1,s2,s,se);
    else if(dp[i][j+1]>dp[i+1][j])
    func(i,j+1,m,n,s1,s2,s,se);
    else
    {
         func(i+1,j,m,n,s1,s2,s,se);
         func(i,j+1,m,n,s1,s2,s,se);
    }
}

int main()
{
 
     ll t;
     cin>>t;
     
     while(t--)
     {
         ll m,n,i,j;string s="";
         cin>>m>>n;
         string s1,s2;
         cin>>s1>>s2;
       
         for(i=m;i>=0;i--)
         {
             for(j=n;j>=0;j--)
             {
                 if(i==m || j==n)
                 dp[i][j]=0;
                 else if(s1[i]==s2[j])
                 {
                       dp[i][j]=dp[i+1][j+1]+1;
                 }
               
                 else
                 dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
             }
         }
         cout<<dp[0][0]<<endl;
         i=0;j=0;s="";set<string>se;set<string>::iterator it;
        func(i,j,m,n,s1,s2,s,se);
     //   cout<<se.size()<<endl;
        for(it=se.begin();it!=se.end();it++)
        cout<<*it<<" ";
        cout<<endl;
     }
   
}
