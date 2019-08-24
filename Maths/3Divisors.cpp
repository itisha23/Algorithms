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
        ll n,i,x,flag,count=0,j;
        cin>>n;
        x=sqrt(n);
        for(i=2;i<=x;i++)
        {
            flag=0;
            for(j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    flag=1;break;
                }
            }
            if(flag==0)
            count++;
            
        }
        cout<<count<<endl;
    }
}
