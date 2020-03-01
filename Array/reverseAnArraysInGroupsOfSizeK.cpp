#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b; i++)
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,k,i,low,high;
        cin>>n>>k;
        ll arr[n];
        
        f(i,0,n)
            cin>>arr[i];
            
        for(i=0; i<n; i+=k) {
            
            low = i;
            high = min(i+k-1, n-1);
            
            while(low<high){
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }
        
        f(i,0,n){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
}