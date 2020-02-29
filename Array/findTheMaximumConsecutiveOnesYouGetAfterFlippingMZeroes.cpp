#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--) {
        ll n,i,start,ans,zeroes,m;
        cin>>n;
        ll arr[n];
        f(i,0,n){
            cin>>arr[i];
        }
        cin>>m;
        start =0;
        ans = INT_MIN;
        zeroes =0;
        f(i,0,n) {
            if(arr[i]==0){
                zeroes++;
            }
            if(zeroes > m) {
                while(arr[start] !=0){
                    start++;
                }
                start++;
                zeroes =m;
            }
            ans = max(ans, i-start+1);
        }
        cout<<ans<<endl;
    }
}