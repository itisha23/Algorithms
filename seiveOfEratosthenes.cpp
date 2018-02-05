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
    ll i,j,cou=0;
   ll prime[10006];

   for(i=1;i<=10005;i++)
    prime[i]=1;

  for(i=2;i*i<=10002;i++)
   {
       if(prime[i]==1)
       {
         for(j=2*i;j<=10002;j+=i)
            prime[j]=0;
       }
   }
   for(i=1000;i<=10002;i++)
    if(prime[i])
     {
         cout<<i<<" ";
       cou++;
       }
     cout<<cou;
   
}


