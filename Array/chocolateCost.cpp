//https://practice.geeksforgeeks.org/problems/chocolate-station/0

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b; i++)
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n, i, p, count=0, ans=0;
        cin>>n;
        ll arr[n+1];
        arr[0] = 0;
        f(i,1,n+1)
            cin>>arr[i];
        cin>>p;
        f(i,0,n){
            count+=  arr[i]-arr[i+1];
            if(count<0){
                ans+= abs(count)*p;
                count=0;
            }
        }
        cout<<ans<<endl;
    }
}