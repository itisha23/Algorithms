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
        ll n,i,x,b,count=0;
        cin>>n;
        for(i=1;i<=cbrt(n);i++)
        {
            x=i*i*i;
            b=cbrt(n-x);
            if(b*b*b == (n-x))
             count++;
        }
        cout<<count<<endl;
    }
}
