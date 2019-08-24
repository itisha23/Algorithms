#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,ans;
        cin>>n;
        
        while(n%2==0)
        {
            ans=2;
            n=n/2;
        }
        
        for(i=3;i<=sqrt(n);i++)
        {
            while(n%i==0)
            {
                ans=i;
                n=n/i;
            }
        }
        if(n>2)
        ans=n;
        cout<<ans<<endl;
        
    }
}
