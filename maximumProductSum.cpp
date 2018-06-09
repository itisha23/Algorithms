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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,ans=INT_MIN,j,pro1,pro2;
        cin>>n;
        ll arr[n];
        f(i,0,n)
         cin>>arr[i];
        ll max_ending_here[n];
        ll min_ending_here[n];
         max_ending_here[0]=arr[0];
         min_ending_here[0]=arr[0];
        f(i,1,n)
        {
            max_ending_here[i]=max(arr[i]*max_ending_here[i-1],max(arr[i],min_ending_here[i-1]*arr[i]));
            min_ending_here[i]=min(arr[i],min(min_ending_here[i-1]*arr[i],max_ending_here[i-1]*arr[i]));
        }
        /*
        f(i,0,n)
        cout<<max_ending_here[i]<<" ";
        cout<<endl;
        f(i,0,n)
        cout<<min_ending_here[i]<<" ";
        cout<<endl;*/
        f(i,0,n)
        ans=max(ans,max_ending_here[i]);
        cout<<ans<<endl;

    }

    
}


