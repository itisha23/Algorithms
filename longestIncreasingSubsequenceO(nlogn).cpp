#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e18
#define f(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,x,ans=INT_MIN,a;
        cin>>n;
        a=n+1;
        vector<ll>vec(a);
        f(i,1,n+1)
        cin>>vec[i];
        ll dp[n+1];
        vector<ll>c(a);
        c[0]=-inf;
        f(i,1,n+1)
        c[i]=inf;
        f(i,1,n+1)
        {
            x=lower_bound(c.begin(),c.end(),vec[i])-c.begin();
            c[x]=vec[i];
            dp[i]=x;
        }
        f(i,1,n+1)
        ans=max(ans,dp[i]);
        if(n==0)
        cout<<0<<endl;
        else
        cout<<ans<<endl;
    }
}
