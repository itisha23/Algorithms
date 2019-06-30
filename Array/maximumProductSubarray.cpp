#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,max_ending_here,min_ending_here,ans,temp;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        max_ending_here=arr[0];
        min_ending_here=arr[0];
        ans=arr[0];
        f(i,1,n){
            temp=max_ending_here;
            max_ending_here=max(arr[i],max(max_ending_here*arr[i],min_ending_here*arr[i]));
            min_ending_here=min(arr[i],min(min_ending_here*arr[i],temp*arr[i]));
            ans=max(ans,max_ending_here);
        }
        
        cout<<ans<<endl;
    }
}
