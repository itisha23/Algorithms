#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        
        for(i=0;i<n;i+=2){
            if(i>0 && arr[i]<arr[i-1])
                swap(arr[i],arr[i-1]);
            if(i<n-1 && arr[i]<arr[i+1])
                swap(arr[i],arr[i+1]);
        }
        
        f(i,0,n)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}
